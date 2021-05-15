#include <iostream>
#include <list>
#include <vector>

using namespace std;
class HashTable
{
	static const int tableSize = 10;
	list<pair<int, list<string>>> table[tableSize];
	
public:
	bool isEmpty() const;
	int hashFunction(int key);
	void insertItem(int key, string val);
	void removeLastItem(int key);
	void removeCertainItem(int key, string val);
	list<string>* searchValues(int key);
	void printTable();

};
bool HashTable::isEmpty() const
{
	int sum = 0;
	for (auto& e : table)
	{
		sum += e.size();
	}
	if (!sum)
		return true;
	return false;
}

int HashTable::hashFunction(int key) // sum each digit and % tableSize
{
	int sum = 0;
	while (key>=10)
	{
		sum += (key % 10);
		key /= 10;
	}
	sum += key ;
	return sum % tableSize;
}
void HashTable::insertItem(int key, string val)
{
	int hashIdx = hashFunction(key);
	bool keyExist = false;
	for (auto& e : table[hashIdx])
	{
		if (e.first == key)
		{
			keyExist = true;
			e.second.push_back(val);
			break;
		}	
	}
	if(!keyExist)
	{
		list<string> newList;
		newList.push_back(val);
		table[hashIdx].push_back(make_pair(key, newList));
	}
}
void HashTable::removeLastItem(int key)
{
	list<string>* tmp = searchValues(key);
	if (!tmp)
		cout << "There is no key in table" << endl;
	else
		tmp->pop_back();
}
void HashTable::removeCertainItem(int key, string val)
{
	list<string>* tmp = searchValues(key);
	if (!tmp)
		cout << "There is no key and value in table" << endl;
	else
	{
		tmp->remove(val);
	}
}
list<string>* HashTable::searchValues(int key)
{

	int hashIdx = hashFunction(key);
	for (auto& pair : table[hashIdx])
	{
		if (pair.first == key)
			return &pair.second;
	}
	return nullptr;
}
void HashTable::printTable()
{
	for (auto& node : table)
	{
		for (auto& pair : node)
		{
			cout << pair.first << ": ";
			for (auto& s : pair.second)
				cout << s << " ";
			cout << endl;
		}
		cout << endl;
	}
}
int main()
{
	HashTable ht;
	ht.insertItem(123, "123");
	ht.insertItem(123, "6");
	ht.insertItem(456, "456");
	ht.printTable();

	ht.removeCertainItem(123,"123");
	ht.printTable();
	return 0;
}
