class Node
{
public:
	int val;
	Node* next = nullptr;
	Node(int v = -1)
	{
		val = v;
	}
};


class Queue
{
	Node* head = new Node();
	Node* tail = head;
public:
	void enQueue(int val)
	{
		Node* node = new Node(val);
		tail->next = node;
		tail = node;
	}
	int dequeue()
	{
		if (head->next == nullptr)
			return -1;
		Node* cur = head->next;
		int val = cur->val;
		head->next = head->next->next;
		delete cur;
		return val;
	}
	void printNodes()
	{
		Node* cur = head->next;
		while (cur != nullptr)
		{
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << endl;
	}
};
