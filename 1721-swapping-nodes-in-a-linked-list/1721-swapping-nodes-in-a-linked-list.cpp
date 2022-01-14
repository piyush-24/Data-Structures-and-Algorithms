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
    ListNode* swapNodes(ListNode* head, int k)
    {
        ListNode* temp=head;
        int c=0;
        while(temp!=NULL)
        {
            c++;
            temp=temp->next;
        }
        int lk=c-k+1;
        
        ListNode* x;
        ListNode* y;
        temp=head;
        c=0;
        while(temp!=NULL)
        {
            c++;
            if(c==k)
                x=temp;
            if(c==lk)
                y=temp;
            temp=temp->next;
        }
        swap(x->val,y->val);
        return head;
        
        
    }
};