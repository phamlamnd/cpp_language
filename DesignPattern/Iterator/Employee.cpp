#include "Employee.h"

void Developer::show()
{
	cout << "I'm DEVELOPER" << endl;
}

void Tester::show()
{
	cout << "I.m TESTER" << endl;
}

void Manager::show()
{
	cout << "I'm MANAGER" << endl;
}

Employee* EmployeeFactory::getEmployee(EmployeeType type)
{
	Employee *employee = NULL;
	switch (type)
	{
	case DEVELOPER:
		employee = new Developer();
		break;
	case TESTER:
		employee = new Tester();
		break;
	case MANAGER:
		employee = new Manager();
		break;
	default:
		break;
	}
	return employee;
}