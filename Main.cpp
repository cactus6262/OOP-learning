#include "Stack.h"
#include "Queue.h"
#include "Graph.h"
#include "Tester.h"
#include "Hash.h"
#include <string>

string* findBin(int n)
{
	string* result = new string[n];
	myQueue q(n + 1);
	q.enqueue(1);

	string s1, s2;

	for (int i = 0; i < n; ++i)
	{
		result[i] = to_string(q.dequeue());
		s1 = result[i] + "0";
		s2 = result[i] + "1";

		q.enqueue(stoi(s1));
		q.enqueue(stoi(s2));
	}

	return result;
}

void testGraph()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 3);
	cout << endl;
	g.printGraph();
}

void test_findBin()
{
	auto res = findBin(4);

	for (int i = 0; i < 4; ++i)
		cout << res[i] << endl;
}

void testHashTable()
{
	int *ptr = new int[9999999];
	HashTable ht(4);
	ht.insert("London", 2);

	ht.insert("London", 10);
	ht.insert("New York", 15);
	ht.insert("Tokyo", 7);
	ht.insert("Bangkok", 2);
	ht.insert("Beijing", 6);
	ht.insert("Islamabad", 9);
	ht.insert("New Delhi", 17);
	ht.insert("Moscow", 12);
	ht.display();
	ht.resize();
	ht.display();
	ht.insert("Amsterdam", 5);
	ht.insert("Paris", 13);
	ht.insert("Istanbul", 19);
	ht.insert("Kuala Lumpur", 1);
	ht.insert("Jakarta", 8);
	ht.insert("Glasgow", 3);
	ht.insert("Seattle", 14);
	cout << ht.searchKey("London") << endl;
	cout << ht.searchKey("Moscow") << endl;
	cout << ht.searchKey("Berlin") << endl;
	ht.display();
	ht.deleteKey("London");
	ht.display();
	ht.deleteKey("Moscow");
	ht.display();
	ht.deleteKey("Istanbul");
	ht.display();
}

int main()
{

	Tester myTest("data structure Test");
	myTest.addTest(testGraph, "test Graph Class");
	myTest.addTest(test_findBin, "test queue Class");

	myTest.runTest();

	cout << "press Enter to exit" << endl;
	getchar();
	return 0;
}

