
#include "Singleton.h"
#include <iostream>
using namespace std;

Singleton* Singleton::getInstance()
{
	if (instance == nullptr)
		instance = new Singleton();

	return instance;
}
Singleton* Singleton::instance = 0;
Singleton::Singleton()
{

}

void testSingleton()
{
	//new Singleton(); // Won't work
	Singleton* s = Singleton::getInstance(); // Ok
	Singleton* r = Singleton::getInstance();

	/* The addresses will be the same. */
	std::cout << s << std::endl;
	std::cout << r << std::endl;
}