#pragma once
#include <iostream>
#include <map>
#include "globalFile.h"
#include <string>
#include <fstream>

class OrderFile
{
public:
	OrderFile();

	void updateOrder();

	std::map<int, std::map<std::string, std::string>> m_orderDate;

	int m_size;
};
