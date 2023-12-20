#include "orderFile.h"

OrderFile::OrderFile()
{
	std::ifstream ifs;
	ifs.open(ORDER_FILE, std::ios::in);

	std::string date;
	std::string interval;
	std::string stuId;
	std::string stuName;
	std::string roomId;
	std::string status;

	this->m_size = 0;

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		std::string key;
		std::string value;
		std::map<std::string, std::string> m;
		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos);
			m.insert(std::make_pair(key, value));
		}

		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos);
			m.insert(std::make_pair(key, value));
		}

		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos);
			m.insert(std::make_pair(key, value));
		}

		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos);
			m.insert(std::make_pair(key, value));
		}

		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos);
			m.insert(std::make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos);
			m.insert(std::make_pair(key, value));
		}

		this->m_orderDate.insert(std::make_pair(this->m_size, m));
		this->m_size++;
	}
}

void OrderFile::updateOrder()
{
	if (this->m_size == 0)
	{
		return;
	}

	std::ofstream ofs(ORDER_FILE, std::ios::out | std::ios::trunc);
	for (int i = 0; i < m_size; i++)
	{
		ofs << "date: " << this->m_orderDate[i]["date"] << " ";
		ofs << "interval: " << this->m_orderDate[i]["interval"] << " ";
		ofs << "stuId: " << this->m_orderDate[i]["stuId"] << " ";
		ofs << "stuName: " << this->m_orderDate[i]["stuName"] << " ";
		ofs << "roomId: " << this->m_orderDate[i]["roomId"] << " ";
		ofs << "status: " << this->m_orderDate[i]["status"] << " ";
	}
	ofs.close();
}