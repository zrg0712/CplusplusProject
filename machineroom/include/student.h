#pragma once
#include "identity.h"
#include <fstream>
#include "globalFile.h"
#include "computerRoom.h"
#include <vector>
#include "orderFile.h"

class Student :public Identity
{
public:
	Student();

	Student(int id, std::string name, std::string pwd);

	void operMenu() override;

	void applyOrder();

	void showMyOrder();

	void showAllOrder();

	void cancelOrder();

	int m_id;
	std::vector<ComputerRoom> vCom;
};