#include <iostream>
#include <assert.h>

using namespace std;

class DLinkedList
{
public:
	int val = 0;
	DLinkedList* next = nullptr;
	DLinkedList* prev = nullptr;

	DLinkedList(int i)
	{
		val = i;
	}
	DLinkedList()
	{}
	
};

void addAtHead(DLinkedList& head, int i)
{
	DLinkedList* node = new DLinkedList(i);
	if (head.next == nullptr)
	{
		head.next = node;
		node->prev = nullptr;
	}
	else
	{
		node->next = head.next;
		head.next = node;
		node->next->prev = node;
	}
	
	
}

void printNodes(DLinkedList& head)
{
	DLinkedList* cur = head.next;
	while (cur != nullptr)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}

void addAtBack(DLinkedList& head, int i)
{
	DLinkedList* node = new DLinkedList(i);
	if (head.next == nullptr)
		head.next = node;
	else
	{
		DLinkedList* cur = head.next;
		while (cur->next != nullptr)
		{
			cur = cur->next;
		}
		cur->next = node;
		node->prev = cur;
	}
}

DLinkedList& find(DLinkedList& head, int i)
{
	DLinkedList* cur = head.next;
	while (cur != nullptr)
	{
		if (cur->val == i)
			return *cur;
		cur = cur->next;
	}
	cout << "No node find" << endl;
	throw overflow_error("No node fine");
}
void addAfter(DLinkedList& target, int i)
{
	DLinkedList* node = new DLinkedList(i);

	if (target.next == nullptr)
	{
		target.next = node;
		node->prev = &target;
	}
		
	else
	{
		node->next = target.next;
		target.next = node;
		node->prev = &target;
		node->next->prev = node;
	}
}

void deleteNode(DLinkedList& node)
{
	DLinkedList* target = &node;
	target->prev->next = target->next;
	target->next->prev = target->prev;
	delete target;
}
