/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
    Node* dummy = new Node(0);
    Node* copy = dummy;
    unordered_map<Node*, Node*> um;
    while (cur != nullptr)
    {
        int val = cur->val;
        Node* newNode = new Node(val);
        copy->next = newNode;
        um[cur] = newNode;

        cur = cur->next;
        copy = copy->next;
    }
    cur = head;
    copy = dummy->next;
    while (cur != nullptr)
    {
        Node* ref = cur->random;
        copy->random = um[ref];
        cur = cur->next;
        copy = copy->next;
    }
    return dummy->next;
    }
};
