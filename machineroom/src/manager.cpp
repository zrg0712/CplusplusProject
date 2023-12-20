#include "manager.h"

void printStudent(Student& s)
{
	std::cout << "Number: " << s.m_id << "name: " << s.m_name << "password: " << s.m_pwd << std::endl;
}

void printTeacher(Teacher& t)
{
	std::cout << "Number: " << t.m_emp_id << "name: " << t.m_name << "password: " << t.m_pwd << std::endl;
}

Manager::Manager()
{

}

Manager::Manager(std::string name, std::string pwd)
{
	this->m_name = name;
	this->m_pwd = pwd;
	initVector();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (std::vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		}
	}
	else
	{
		for (std::vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_emp_id)
			{
				return true;
			}
		}
	}
	return false;
}

void Manager::initVector()
{
	std::ifstream ifs;
	ifs.open(STUDENT_FILE, std::ios::in);
	if (!ifs.is_open())
	{
		std::cout << "Read File Failure" << std::endl;
		return;
	}

	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		vStu.push_back(s);
	}
	std::cout << "the Number of Student is: " << vStu.size() << std::endl;
	ifs.close();

	ifs.open(TEACHER_FILE, std::ios::in);
	Teacher t;
	while (ifs >> t.m_emp_id && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		vTea.push_back(t);
	}

	std::cout << "the Number of Teacher is: " << vTea.size() << std::endl;
	ifs.close();

	ifs.open(COMPUTER_FILE, std::ios::in);
	ComputerRoom c;
	while (ifs >> c.m_comid && ifs >> c.m_maxnum)
	{
		vCom.push_back(c);
	}
	std::cout << "the Number of ComputerRoom is: " << vCom.size() << std::endl;
	ifs.close();
}

void Manager::operMenu()
{
	std::cout << "Welcome Manager: " << this->m_name << " LogIn!" << std::endl;
	std::cout << "\t\t-----------------------------------------\n";
	std::cout << "\t\t|                                        |\n";
	std::cout << "\t\t|           1、Add Account               |\n";
	std::cout << "\t\t|                                        |\n";
	std::cout << "\t\t|           2、Check Account             |\n";
	std::cout << "\t\t|                                        |\n";
	std::cout << "\t\t|           3、Check ComputerRoom        |\n";
	std::cout << "\t\t|                                        |\n";
	std::cout << "\t\t|           4、Clean Order               |\n";
	std::cout << "\t\t|                                        |\n";
	std::cout << "\t\t|           0、Exit                      |\n";
	std::cout << "\t\t|                                        |\n";
	std::cout << "\t\t-----------------------------------------\n";
	std::cout << "Please Input You Choice: ";
}

void Manager::addPerson() 
{
	std::cout << "Please Comfirm Account Type: " << std::endl;
	std::cout << "1、Add a Student" << std::endl;
	std::cout << "2、Add a Teacher" << std::endl;

	std::string fileName;
	std::string tip;
	std::string errorTip;
	std::ofstream ofs;

	int select = 0;
	std::cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "Please Input Student Number: ";
		errorTip = "Student Repeated, Please Input Again: ";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "Please Input Teacher Number: ";
		errorTip = "Teacher Repeated, Please Input Again: ";
	}

	ofs.open(fileName, std::ios::out | std::ios::app);
	int id;
	std::string name;
	std::string pwd;
	std::cout << tip << std::endl;
	while (true)
	{
		std::cin >> id;
		bool ret = this->checkRepeat(id, select);

		if (ret)
		{
			std::cout << errorTip << std::endl;
		}
		else
		{
			break;
		}
	}

	std::cout << "Please Input Name: " << std::endl;
	std::cin >> name;

	std::cout << "Please Input Password: " << std::endl;
	std::cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << std::endl;
	std::cout << "Add Successfully" << std::endl;
	system("pause");
	system("cls");
	ofs.close();
	this->initVector();
}

void Manager::showPerson()
{
	std::cout << "Please Show Content: " << std::endl;
	std::cout << "1. All of Student" << std::endl;
	std::cout << "2. All of Teacher" << std::endl;

	int select = 0;
	std::cin >> select;

	if (select == 1)
	{
		std::cout << "All of Student Message: " << std::endl;
		std::for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		std::cout << "All of Teacher Message: " << std::endl;
		std::for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

void Manager::showComputer()
{
	std::cout << "the ComputerRoom Message is: " << std::endl;
	for (auto it = vCom.begin(); it != vCom.end(); it++)
	{
		std::cout << "Computer Room Number: " << it->m_comid << " Capacity is: " << it->m_maxnum << std::endl;
	}
	system("pause");
	system("cls");
}

void Manager::cleanFile()
{
	std::ofstream ofs;
	ofs.open(ORDER_FILE, std::ios::trunc);
	ofs.close();

	std::cout << "Clean File Success!" << std::endl;
	system("pause");
	system("cls");
}