#ifndef TESTER_HPP
#define TESTER_HPP

#include <string>
#include <vector>
#include <functional>
using namespace std;

class Tester
{
public:
	Tester(const string name);
	void addTest(const function<void()>& testFunc, string testName);
	void runTest();
private:
	string name;
	vector<pair<function<void()>, string>> testCases;
};

#endif
