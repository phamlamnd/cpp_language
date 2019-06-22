#include <iostream> 
using namespace std;

enum EmployeeType{DEVELOPER, TESTER, MANAGER};

class Employee
{
public:
	virtual void show() = 0;
};

class Developer : public Employee
{
public:
	void show() 
	{
		cout << "I'm DEVELOPER" << endl;
	}
};

class Tester : public Employee
{
public:
	void show() 
	{
		cout << "I.m TESTER" << endl;
	}
};

class Manager : public Employee
{
public:
	void show() 
	{
		cout << "I'm MANAGER" << endl;
	}
};

class EmployeeFactory
{
public:
	static Employee* getEmployee(EmployeeType type) 
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
};

int main() 
{
	Employee *employee = EmployeeFactory::getEmployee(MANAGER);
	employee->show();

	system("pause");
	return 0;
}