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
    void reorderList(ListNode* head) {  // 1-2-3-4-5  => 1-5-2-4-3
        int count = 0;
        ListNode* cur = head;
        while(cur!= nullptr)
        {
            count ++;
            cur=cur->next;
        }
        int mid = count/2;
        if(mid != 0)
        {
             ListNode* first = head;
        ListNode* second;
        ListNode* prev = head;
        
        // split into first and second list
        for(int i=0;i<mid-1;i++)
        {
            prev = prev->next;
        }
        second = prev->next;
        prev->next = nullptr;
        
        //reverse second list
        vector<ListNode*> v;
        cur = second;
        while(cur!=nullptr)
        {
            v.push_back(cur);
            cur = cur->next;
        }
        for(int i= v.size()-1; i>0; i--)
        {
            v[i]->next = v[i-1];
        }
        v[0]->next = nullptr;
        second = v.back();
       
        //merge
        cur = first;
        count = 1;
        while(first!=nullptr)
        {
            if(second==nullptr)
            {
                cur->next = first;
                break;
            }
             if(count%2 !=0)
            {
                  first = first->next;
                  cur->next = second;
            }
            else
            {
                  second = second->next;
                  cur->next = first;
            }
                    cur = cur->next;
                   count++;
        
        }
           
     
        head = first;
       
        }
            
       
    }
};
