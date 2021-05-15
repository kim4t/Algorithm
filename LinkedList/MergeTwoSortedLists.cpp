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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* dummy = new ListNode();
		ListNode* cur = dummy;
		while (1)
		{
			if (l1 == NULL && l2 == NULL)
				break;
			else if (l1 == NULL)
			{
				cur->next = l2;
				break;
			}
			else if (l2 == NULL)
			{
				cur->next = l1;
				break;
			}
			else if (l1->val <= l2->val)
			{
				cur->next = l1;
				l1 = l1->next;
			}
			else
			{
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		return dummy->next;
    }
};
