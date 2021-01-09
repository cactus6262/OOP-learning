#include "Hash.h"
#include <iostream>
using namespace std;

HashEntry::HashEntry()
{
	key = "";
	value = -1;
	next = nullptr;
}
HashEntry::HashEntry(string key, int value)
{
	this->key = key;
	this->value = value;
}


HashTable::HashTable(int s)
{
	slots = s;
	size = 0;
	buckets = new HashEntry * [s];

	for (int i = 0; i < s; ++i)
		buckets[i] = nullptr;
}
int HashTable::getSize()
{
	return size;
}
bool HashTable::isEmpty()
{
	return getSize() == 0;
}
int HashTable::getSlotIndex(string key)
{
	int key_int = 0;
	for (auto& ch : key)
		key_int = key_int * 37 + ch;

	key_int = abs(key_int);

	return key_int % slots;
}
void HashTable::insert(string key, int value)
{
	int index = getSlotIndex(key);

	//check if the entry for the index exists?
	if (buckets[index] == nullptr)
	{
		buckets[index] = new HashEntry(key, value);
		++size;
	}
	else
	{
		HashEntry* curr = buckets[index];
		while (curr && curr->next)
			curr = curr->next;

		curr->next = new HashEntry(key, value);
		++size;
	}
}

void HashTable::resize() {
	cout << "resize" << endl;
	slots *= 2;
	HashEntry ** tempBucket = new HashEntry *[slots];
	int hashIndex;
	HashEntry * tmp;
	for (int i = 0; i < slots; i++)
		tempBucket[i] = NULL;
	HashEntry * temp;
	for (int i = 0; i < slots / 2; i++) {
		if (buckets[i] != NULL) {

			temp = buckets[i];
			while (temp != NULL) {
				hashIndex = getSlotIndex(temp->key);
				if (tempBucket[hashIndex] == NULL)
					tempBucket[hashIndex] = new HashEntry(temp->key, temp->value);
				else { //find next free space

					tmp = tempBucket[hashIndex];;
					while (tmp->next != NULL) {
						tmp = tmp->next;
					}
					tmp->next = new HashEntry(temp->key, temp->value);
				}
				temp = temp->next;
			}
		}
	}
	buckets = tempBucket;
}

void HashTable::display() {
	HashEntry * temp;
	for (int i = 0; i < slots; i++) {
		if (buckets[i] != NULL) {
			cout << "HashIndex : " << i << " ";
			temp = buckets[i];
			while (temp != NULL) {
				cout << "(key = " << temp->key << " , value = " << temp->value << " )";
				temp = temp->next;
			}
		}
		cout << endl;
	}
}

int HashTable::searchKey(string key)
{
	int index = getSlotIndex(key);
	if (buckets[index] == nullptr)
	{
		cout << "key not found" << endl;
		return -1;
	}
	else
	{
		HashEntry* curr = buckets[index];
		while (curr)
		{
			if (curr->key == key)
				return curr->value;
			curr = curr->next;
		}
	}

	cout << "key not found" << endl;
	return -1;
}

void HashTable::deleteKey(string key)
{
	int index = getSlotIndex(key);
	if (buckets[index] == nullptr)
	{
		cout << "key to be deleted is not found" << endl;
		return;
	}
	else
	{
		HashEntry* curr = buckets[index];
		HashEntry* prev = curr;
		if (curr->key == key)
		{
			curr = curr->next;
		}
		else
		{
			while (curr)
			{
				if (curr->key == key)
				{
					prev->next = curr->next;
					return;
				}

				prev = curr;
				curr = curr->next;
			}

			cout << "key to be deleted is not found" << endl;
			return;
		}
	}
}