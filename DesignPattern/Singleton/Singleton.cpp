#include <iostream>
using namespace std;

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

template <class T>
class Singleton
{
private:
	static T* singleton;
	Singleton() {}
	~Singleton() {}
	Singleton(const Singleton&) {}
	Singleton& operator=(const Singleton&) {}
public:
	static T* getInstance();
};

template <class T>
T* Singleton<T>::singleton = NULL;

template <class T>
T* Singleton<T>::getInstance()
{
	if (!singleton)
	{
		singleton = new T();
	}
	return singleton;

}

int main()
{
	Employee *e = Singleton<Manager>::getInstance();
	e->show();

	system("pause");
	return 0;
}