#pragma once
#include "identity.h"
#include <fstream>
#include "globalFile.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include <algorithm>
#include "computerRoom.h"


void printStudent(Student& s);

void printTeacher(Teacher& t);

class Manager :public Identity
{
public:
	Manager();

	Manager(std::string name, std::string pwd);

	void initVector();

	void operMenu() override;

	void addPerson();

	void showPerson();

	void showComputer();

	void cleanFile();
	bool checkRepeat(int id, int type);

	std::vector<Student> vStu;

	std::vector<Teacher> vTea;

	std::vector<ComputerRoom> vCom;
};