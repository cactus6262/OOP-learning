#ifndef HASH_HPP
#define HASH_HPP

#include <string>
using namespace std;

class HashEntry
{
public:
	string key;
	int value;
	HashEntry* next;
	HashEntry();
	HashEntry(string key, int value);
private:
};

class HashTable
{
public:
	HashTable(int s);
	int getSize();
	bool isEmpty();
	int getSlotIndex(string key);
	void insert(string key, int value);
	void resize();
	void display();
	int searchKey(string key);
	void deleteKey(string key);
private:
	HashEntry** buckets;
	int slots;
	int size;
};

#endif
