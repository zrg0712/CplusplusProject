#include "student.h"

Student::Student()
{

}


Student::Student(int id, std::string name, std::string pwd)
{
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;

	std::ifstream ifs;
	ifs.open(COMPUTER_FILE, std::ios::in);

	ComputerRoom c;
	while (ifs>>c.m_comid&&ifs>>c.m_maxnum)
	{
		vCom.push_back(c);
	}
	ifs.close();
}

void Student::operMenu()
{
	std::cout << "Welcome Student: " << this->m_name << " LogIn!" << std::endl;
	std::cout << "\t\t-----------------------------------------\n";
	std::cout << "\t\t|                                        |\n";
	std::cout << "\t\t|           1、Apply Appointment         |\n";
	std::cout << "\t\t|                                        |\n";
	std::cout << "\t\t|           2、Show Own Appointment      |\n";
	std::cout << "\t\t|                                        |\n";
	std::cout << "\t\t|           3、Show All Appointment      |\n";
	std::cout << "\t\t|                                        |\n";
	std::cout << "\t\t|           4、Cancel Order              |\n";
	std::cout << "\t\t|                                        |\n";
	std::cout << "\t\t|           0、Exit                      |\n";
	std::cout << "\t\t|                                        |\n";
	std::cout << "\t\t-----------------------------------------\n";
	std::cout << "Please Input You Choice: ";
}

void Student::applyOrder()
{
	std::cout << "Please Input Your Date: " << std::endl;
	std::cout << "1、Mon" << std::endl;
	std::cout << "2、Tue" << std::endl;
	std::cout << "3、Wed" << std::endl;
	std::cout << "4、Thu" << std::endl;
	std::cout << "5、Fri" << std::endl;
	int date = 0;
	int interval = 0;
	int room = 0;

	while (true)
	{
		std::cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		std::cout << "Wrong Input, Please Input Again" << std::endl;
	}
	std::cout << "Morning or Afternoon?" << std::endl;
	std::cout << "1、Morning" << std::endl;
	std::cout << "2、Afternoon" << std::endl;
	while (true)
	{
		std::cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		std::cout << "Wrong Input, Please Input Again" << std::endl;
	}
	
	std::cout << "Please Choice ComputerRoom: 1、2、3" << std::endl;
	while (true)
	{
		std::cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		std::cout << "Wrong Input, Please Input Again" << std::endl;
	}

	std::cout << "book successfully, in review" << std::endl;
	
	std::ofstream ofs(ORDER_FILE, std::ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_id << " ";
	ofs << "stuName:" << this->m_name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << std::endl;
	ofs.close();
	system("pause");
	system("cls");
}

void Student::showMyOrder()
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
		if (atoi(of.m_orderDate[i]["stuId"].c_str()) == this->m_id)
		{
			std::cout << "date: " << of.m_orderDate[i]["date"] << " ";
			std::cout << "interval: " << (of.m_orderDate[i]["interval"] == "1" ? "Morning" : "Afternoon") << " ";
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

	}
	system("pause");
	system("cls");
}

void Student::showAllOrder()
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

		std::cout << "date: " << of.m_orderDate[i]["date"]<<" ";
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

void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		std::cout << "No Record" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	
	std::vector<int> v;
	int index = 1;
	for (int i = 0; i < of.m_size; i++)
	{
		if (atoi(of.m_orderDate[i]["stuId"].c_str()) == this->m_id)
		{
			if (of.m_orderDate[i]["status"] == "1" || of.m_orderDate[i]["status"] == "2")
			{
				v.push_back(i);
				std::cout << index++ << " ";
				std::cout << "date: " << of.m_orderDate[i]["date"] << " ";
				std::cout << "interval: " << (of.m_orderDate[i]["interval"] == "1" ? "Morning" : "Afternoon") << " ";
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
		}
	}
	std::cout << "Which Record will be Cancel, 0 is Return" << std::endl;
	int select = 0;
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
				of.m_orderDate[v[select - 1]]["status"] = "0";
				of.updateOrder();
				std::cout << "cancel sucessfully" << std::endl;
				break;
			}
		}
	}
}

