/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head == nullptr)
            return head;
        vector<ListNode*> v;
		while (head != nullptr)
		{
			v.push_back(head);
			head = head->next;
		}
		head = v.back();
        for(int i=v.size()-1; i>0;i--)
        {
            v[i]->next = v[i-1];
        }
        v.front()->next = nullptr;
		return head;
    }
};
