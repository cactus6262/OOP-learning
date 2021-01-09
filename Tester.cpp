
#include "tester.h"

#include <iostream>
using namespace std;

Tester::Tester(const string testName) : name(testName), testCases()
{
}

void Tester::addTest(const function<void()>& testFunc, string testName)
{
	testCases.push_back(make_pair(testFunc, testName));
}

void Tester::runTest()
{
	cout << name << ": Running " << testCases.size() << " Tests" << endl;

	for (auto& test : testCases)
	{
		cout << test.second << "... ";
		test.first(); //run the test
		cout << "OK!" << endl;
	}
}