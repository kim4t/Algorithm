#include <iostream>
#include <stack>

using namespace std;

class TreeNode
{
	
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v) :val(v) {}
};

stack<TreeNode*> stk;

// preorder NLR
void iterativePreOrder(TreeNode* node)
{
	if (!node)
		return;
	stk.push(node);
	while (stk.size()>0)
	{
		TreeNode* top = stk.top();
		cout << top->val << " ";
		stk.pop();
		if (top->right)
			stk.push(top->right);
		if (top->left)
			stk.push(top->left);
	}

}

// inorder LNR
void iterativeInOrder(TreeNode* node)
{
	TreeNode* cur = node;
	while (1)
	{
		if (cur)
		{
			stk.push(cur);
			cur = cur->left;
		}
		else if (stk.size() > 0)
		{
			cur = stk.top();
			stk.pop();
			cout << cur->val << " ";
			cur = cur->right;
		}
		else
			break;
	}
}

// postorder LRN
void iterativePostOrder(TreeNode* node)
{
	TreeNode* cur = node;
	TreeNode* lastVisit = nullptr;
	TreeNode* top = nullptr;
	while (1)
	{
		if (cur)
		{
			stk.push(cur);
			cur = cur->left;
		}
		else if (stk.size() > 0)
		{
			top = stk.top();
			if (top->right && top->right != lastVisit)
				cur = top->right;
			else
			{
				cout << top->val << " ";
				lastVisit = top;
				stk.pop();
			}
		}
		else
			break;
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
	4	  5   6     7
	*/
	node1.left = &node2;			
	node1.right = &node3;
	node2.left = &node4;
	node2.right = &node5;
	node3.left = &node6;
	node3.right = &node7;

	iterativePreOrder(&node1);
	cout << endl;
	iterativeInOrder(&node1);
	cout << endl;
	iterativePostOrder(&node1);
	return 0;
}
