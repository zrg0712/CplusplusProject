/*
学生代表：申请使用，可预约未来一周内的机房使用，预约日期周一至五，时段上午、下午
教师：审核（依据情况审核预约是否通过）
管理员：给学生教师创建账号，负责清空每周申请订单

机房：3间
1号：20
2号：50
3号：100

具体需求：
进入登录界面：
管理员、学生代表、老师、退出
身份验证后，进入子菜单：
学生输入：学号、姓名、登录密码；
老师输入：职工号、姓名、登录密码；
管理员输入：姓名、登录密码；

学生具体功能：
申请预约：预约机房
查看自身预约：查看自己预约的状态
查看所有预约：查看全部预约信息以及预约状态
取消预约：取消自身的预约，预约成功或审核中的预约均可取消

教师具体功能：
查看所有预约：查看全部预约信息以及预约状态
审核预约：对学生的预约进行审核
注销登录：退出登录

管理原具体功能：
添加账号：添加学生或教师的账号，需要检测学生账号或教职工账号是否重复
查看账号：可以选择查看学生或者教师的账号
查看机房：查看所有机房的信息
清空预约：清空所有预约记录
注销登录：退出登录
*/

#include <iostream>
#include "globalFile.h"
#include "identity.h"
#include <fstream>
#include "student.h"
#include "teacher.h"
#include "manager.h"

void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		std::cin >> select;
		
		if (select == 1)
		{
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			std::cout << "Logout" << std::endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

void studentMenu(Identity*& student)
{
	while (true)
	{
		student->operMenu();
		Student* stu = (Student*)student;
		int select = 0;
		
		std::cin >> select;

		if (select == 1)
		{
			stu->applyOrder();
		}
		else if (select == 2)
		{
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			std::cout << "Logout" << std::endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void managerMenu(Identity*& manager);
void loginIn(std::string fileName, int type)
{
	Identity* person = nullptr;
	std::ifstream ifs;
	ifs.open(fileName, std::ios::in);

	if (!ifs.is_open())
	{
		std::cout << "there is no file" << std::endl;
		ifs.close();
		return;
	}

	int id = 0;
	std::string name;
	std::string pwd;
	if (type == 1)
	{
		std::cout << "Please Input Student Number: " << std::endl;
		std::cin >> id;
	}
	else if (type == 2)
	{
		std::cout << "Please Input Teacher Number: " << std::endl;
		std::cin >> id;
	}

	std::cout << "Please Input User Name: " << std::endl;
	std::cin >> name;
	
	std::cout << "Please Input Password: " << std::endl;
	std::cin >> pwd;

	if (type == 1)
	{
		int f_id;
		std::string f_name;
		std::string f_pwd;
		while (ifs >> f_id && ifs >> f_name && ifs >> f_pwd)  // 每次读一行，遇到空格停止
		{
			if (f_id == id && f_name == name && f_pwd == pwd)
			{
				std::cout << "Studer Verify Success" << std::endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				// TODO: 
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		int f_id;
		std::string f_name;
		std::string f_pwd;
		while (ifs >> f_id && ifs >> f_name && ifs >> f_pwd)  // 每次读一行，遇到空格停止
		{
			if (f_id == id && f_name == name && f_pwd == pwd)
			{
				std::cout << "Teacher Verify Success" << std::endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				// TODO: 
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		std::string f_name;
		std::string f_pwd;
		while (ifs >> f_name && ifs >> f_pwd)  // 每次读一行，遇到空格停止
		{
			if (f_name == name && f_pwd == pwd)
			{
				std::cout << "Manager Verify Success" << std::endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				// TODO: 
				managerMenu(person);
				return;
			}
		}
	}
	std::cout << "Authentication login failure!" << std::endl;
	ifs.close();
	system("pause");
	system("cls");
	return;
}

void managerMenu(Identity*& manager)
{
	while (true)
	{
		manager->operMenu();
		
		Manager* man = (Manager*)manager;  // 强转成子类指针, 即可调用子类特有的函数
		int select = 0;
		
		std::cin >> select;
		
		if (select == 1)
		{
			std::cout << "add account: " << std::endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			std::cout << "view accout" << std::endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			std::cout << "view computerRoom" << std::endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			std::cout << "clear order" << std::endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			std::cout << "Logout Success" << std::endl;
			//system("pause");
			system("cls");
			return;
		}
	}
}

int main()
{
	int select;
	while (true)
	{
		std::cout << "====================  Welcome to System  ====================" << std::endl;
		std::cout << std::endl << "Please Inter You Id: " << std::endl;
		std::cout << "\t\t---------------------------------\n";
		std::cout << "\t\t|                                |\n";
		std::cout << "\t\t|           1、Student           |\n";
		std::cout << "\t\t|                                |\n";
		std::cout << "\t\t|           2、Teacher           |\n";
		std::cout << "\t\t|                                |\n";
		std::cout << "\t\t|           3、Administrator     |\n";
		std::cout << "\t\t|                                |\n";
		std::cout << "\t\t|           0、Exit              |\n";
		std::cout << "\t\t|                                |\n";
		std::cout << "\t\t---------------------------------\n";
		std::cout << "Please Input You Choice: ";

		std::cin >> select;

		switch (select)
		{
		case 1:
			loginIn(STUDENT_FILE, select);
			break;
		case 2:
			loginIn(TEACHER_FILE, select);
			break;
		case 3:
			loginIn(ADMIN_FILE, select);
			break;
		case 0:
			std::cout << "Welcome Next Time Use" << std::endl;
			system("pause");
			return 0;
			break;
		default:
			std::cout << "Wrong Input, Choice Again" << std::endl;
			//system("pause");
			system("cls");
			break;
		}
	}

	return 0;
}



