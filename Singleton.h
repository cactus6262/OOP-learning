#ifndef SINGLETON_HPP
#define SINGLETON_HPP

void testSingleton();
class Singleton
{
public:
	static Singleton* getInstance();
	Singleton(const Singleton& other) = delete;
	Singleton& operator=(const Singleton& other) = delete;
private:
	static Singleton* instance;
	Singleton();
};

#endif
