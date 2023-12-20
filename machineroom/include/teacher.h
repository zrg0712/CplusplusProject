#pragma once
#include "identity.h"
#include "orderFile.h"
#include <vector>

class Teacher :public Identity
{
public:
	Teacher();

	Teacher(int emp_id, std::string name, std::string pwd);

	void operMenu() override;

	void showAllOrder();

	void validOrder();

	int m_emp_id;
};