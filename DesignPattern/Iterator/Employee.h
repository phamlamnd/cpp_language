#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <iostream>
using namespace std;

enum EmployeeType { DEVELOPER, TESTER, MANAGER };

class Employee
{
public:
	virtual void show() = 0;
};

class Developer : public Employee
{
public:
	void show();
};

class Tester : public Employee
{
public:
	void show();
};

class Manager : public Employee
{
public:
	void show();
};

class EmployeeFactory
{
public:
	static Employee* getEmployee(EmployeeType type);
};

#endif /*_EMPLOYEE_H_*/