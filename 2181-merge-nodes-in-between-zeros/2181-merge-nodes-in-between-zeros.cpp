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
    ListNode* mergeNodes(ListNode* head)
    {
        int s=0;
        ListNode* temp=head->next;
        ListNode* dummy = new ListNode(0);
        ListNode* x=dummy;
        vector<int> v;
       while(temp!=NULL)
       {
           if(temp->val==0)
           {
               ListNode* y = new ListNode(s);
               x->next=y;
               x=x->next;
               s=0;
           }
           else
               s+=(temp->val);
           temp=temp->next;
       }
        return dummy->next;
    }
};