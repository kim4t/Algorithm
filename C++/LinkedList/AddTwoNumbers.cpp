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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur = l1;
	int carry = 0;
	while (1)
	{
		int v = cur->val + l2->val + carry;
		carry = 0;
		if (v >= 10)
		{
			carry = 1;
			v -= 10;
		}
		cur->val = v;
		if (cur->next == nullptr && l2->next == nullptr)
			break;
		else if (cur->next == nullptr)
		{
			ListNode* node = new ListNode(0);
			cur->next = node;
		}
		else if (l2->next == nullptr)
		{
			ListNode* node = new ListNode(0);
			l2->next = node;
		}
		cur = cur->next;
		l2 = l2->next;
			
	}
    if(carry == 1)
    {
        ListNode* node = new ListNode(1);
        cur->next = node;
    }
	return l1;
    }
};
