#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class TreeNode
{
	
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v) :val(v) {}
};


void treeLevelPrint(TreeNode* node)
{
	queue<TreeNode*> q;
	q.push(node);
	TreeNode* front = nullptr;
	while (q.size() > 0)
	{
		front = q.front();
		cout << front->val << " ";
		q.pop();
		if (front->left)
			q.push(front->left);
			
		if (front->right)
			q.push(front->right);
		
	}
	cout << endl;
}

void treeLevelPrintWithLine(TreeNode* node)
{
	queue<TreeNode*> q;
	q.push(node);
	TreeNode* front = nullptr;
	int count = 0;
	while (q.size() > 0)
	{
		count = q.size();
		vector<TreeNode*> v;
		for (int i = 0; i < count; i++)
		{
			cout << q.front()->val << " ";
			v.push_back(q.front());
			q.pop();
		}
		cout << endl;
		for (auto e : v)
		{
			if (e->left)
				q.push(e->left);

			if (e->right)
				q.push(e->right);
		}
	}
}

int main()
{
    
	
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	TreeNode node4(4);
	TreeNode node5(5);
	TreeNode node6(6);
	TreeNode node7(7);

	/*
			1
		2		3
	    4	   5         6     7
	*/
	node1.left = &node2;			
	node1.right = &node3;
	node2.left = &node4;
	node2.right = &node5;
	node3.left = &node6;
	node3.right = &node7;

	treeLevelPrint(&node1);
	treeLevelPrintWithLine(&node1);
	return 0;
}
