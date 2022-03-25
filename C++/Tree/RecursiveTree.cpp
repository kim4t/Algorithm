#include <iostream>

using namespace std;

class TreeNode
{
	
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v) :val(v) {}
};

// preorder NLR
void recursivePreOrder(TreeNode* node)
{
	if (node == nullptr)
		return;
	cout << node->val << " ";
	recursivePreOrder(node->left);
	recursivePreOrder(node->right);
}

// inorder LNR
void recursiveInOrder(TreeNode* node)
{
	if (node == nullptr)
		return;

	recursiveInOrder(node->left);
	cout << node->val << " ";
	recursiveInOrder(node->right);
}

// postorder LRN
void recursivePostOrder(TreeNode* node)
{
	if (node == nullptr)
		return;

	recursivePostOrder(node->left);
	recursivePostOrder(node->right);
	cout << node->val << " ";
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
	    2             3
	4       5      6      7
	*/
	node1.left = &node2;			
	node1.right = &node3;
	node2.left = &node4;
	node2.right = &node5;
	node3.left = &node6;
	node3.right = &node7;

	recursivePreOrder(&node1);
	cout << endl;
	recursiveInOrder(&node1);
	cout << endl;
	recursivePostOrder(&node1);
	return 0;
}
