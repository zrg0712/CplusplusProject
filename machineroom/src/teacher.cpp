#include "teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(int emp_id, std::string name, std::string pwd)
{
	this->m_emp_id = emp_id;
	this->m_name = name;
	this->m_pwd = pwd;
}

void Teacher::operMenu()
{
	std::cout << "Welcome Teacher: " << this->m_name << " LogIn!" << std::endl;
	std::cout << "\t\t-----------------------------------------\n";
	std::cout << "\t\t|                                        |\n";
	std::cout << "\t\t|           1、Show All Appointment      |\n";
	std::cout << "\t\t|                                        |\n";
	std::cout << "\t\t|           2、Check Appointment         |\n";
	std::cout << "\t\t|                                        |\n";
	std::cout << "\t\t|           0、Exit                      |\n";
	std::cout << "\t\t|                                        |\n";
	std::cout << "\t\t-----------------------------------------\n";
	std::cout << "Please Input You Choice: ";
}

void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		std::cout << "No Record" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		std::cout << i + 1 << " ";
		std::cout << "date: " << of.m_orderDate[i]["date"] << " ";
		std::cout << "interval: " << (of.m_orderDate[i]["interval"] == "1" ? "Morning" : "Afternoon") << " ";
		std::cout << "stuId: " << of.m_orderDate[i]["stuId"] << " ";
		std::cout << "stuName: " << of.m_orderDate[i]["stuName"] << " ";
		std::cout << "roomId: " << of.m_orderDate[i]["roomId"] << " ";
		std::string status = "status: ";
		if (of.m_orderDate[i]["status"] == "1")
		{
			status += "in review";
		}
		else if (of.m_orderDate[i]["status"] == "2")
		{
			status += "book successully";
		}
		else if (of.m_orderDate[i]["status"] == "-1")
		{
			status += "No Pass";
		}
		else
		{
			status += "cancel appoinment";
		}
		std::cout << status << std::endl;
	}
	system("pause");
	system("cls");
}

void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		std::cout << "No Record" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	std::cout << "apply record message: " << std::endl;
	std::vector<int> v;
	int index = 0;
	for (int i = 0; i < of.m_size; i++)
	{
		if (of.m_orderDate[i]["status"] == "1")
		{
			v.push_back(i);
			std::cout << ++index << " ";
			std::cout << "date: " << of.m_orderDate[i]["date"] << " ";
			std::cout << "interval: " << (of.m_orderDate[i]["interval"] == "1" ? "Morning" : "Afternoon") << " ";
			std::cout << "stuId: " << of.m_orderDate[i]["stuId"] << " ";
			std::cout << "stuName: " << of.m_orderDate[i]["stuName"] << " ";
			std::cout << "roomId: " << of.m_orderDate[i]["roomId"] << " ";
			std::string status = "status: ";
			if (of.m_orderDate[i]["status"] == "1")
			{
				status += "in review";
			}
			std::cout << status << std::endl;
		}
	}
	std::cout << "which record to check, 0 is return" << std::endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		std::cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				std::cout << "Please Input Check Result: " << std::endl;
				std::cout << "1、Pass" << std::endl;
				std::cout << "2、No Pass" << std::endl;
				std::cin >> ret;

				if (ret == 1)
				{
					of.m_orderDate[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderDate[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				std::cout << "Check Over" << std::endl;
				break;
			}
		}
	}
	system("pause");
	system("cls");
}




