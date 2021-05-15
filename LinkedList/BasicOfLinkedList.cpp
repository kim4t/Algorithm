class SLinkedList
{
public:
	int val = 0;
	SLinkedList* next = nullptr;

	SLinkedList(int i)
	{
		val = i;
	}
	SLinkedList()
	{}
	
};

void addAtHead(SLinkedList& head, int i)
{
	
	SLinkedList* node = new SLinkedList(i);
	node->next = head.next;
	head.next = node;
}

void printNodes(SLinkedList& head)
{
	SLinkedList* cur = head.next;
	while (cur != nullptr)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}

void addAtBack(SLinkedList& head, int i)
{
	SLinkedList* node = new SLinkedList(i);
	if (head.next == nullptr)
		head.next = node;
	else
	{
		SLinkedList* cur = head.next;
		while (cur->next != nullptr)
		{
			cur = cur->next;
		}
		cur->next = node;
	}
}

SLinkedList& find(SLinkedList& head, int i)
{
	SLinkedList* cur = head.next;
	while (cur != nullptr)
	{
		if (cur->val == i)
			return *cur;
		cur = cur->next;
	}
	cout << "No node find" << endl;
	assert(0);
}
void addAfter(SLinkedList& target, int i)
{
	SLinkedList* node = new SLinkedList(i);

	if (target.next == nullptr)
		target.next = node;
	else
	{
		node->next = target.next;
		target.next = node;
	}
}

void deleteAfter(SLinkedList& prev)
{
	SLinkedList* target = prev.next;
	prev.next = prev.next->next;
	delete target;
}
