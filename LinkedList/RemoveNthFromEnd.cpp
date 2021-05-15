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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
   ListNode* cur = head;
	int size = 0;
	while (cur != nullptr)
	{
		size++;
		cur = cur->next;
	}
	cout << size << endl;
	int targetIdx = size - n;
	if (targetIdx == 0)
		return head->next;

	ListNode* prev = head;
	for (int i = 0; i < targetIdx - 1; i++)
		prev = prev->next;
	cur = prev->next;
	prev->next = cur->next;
	delete cur;
	return head;
    }
};
