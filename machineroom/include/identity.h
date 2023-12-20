#pragma once
#include <iostream>
#include <string>

class Identity
{
public:
	virtual void operMenu() = 0;

	std::string m_name;
	std::string m_pwd;
};