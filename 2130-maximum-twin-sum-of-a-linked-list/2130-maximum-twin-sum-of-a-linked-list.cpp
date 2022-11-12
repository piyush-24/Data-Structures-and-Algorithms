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
     ListNode* rev(ListNode* head)
    {
         if(head==NULL)
             return NULL;
         if(head->next==NULL)
             return head;
         
        ListNode* d=NULL;
        ListNode* next;
        ListNode* h1=head;
         
        while(h1!=NULL)
        {
            next=h1->next;
            h1->next=d;
            d=h1;
            h1=next;
        }
        return d;
    }
     ListNode* mid(ListNode* head) 
    {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL &&  fast->next->next!=NULL)
        {
            fast=(fast->next)->next;
            slow=slow->next;
        }
        return slow;
    }
    int pairSum(ListNode* head)
    {
        ListNode* m=mid(head);
        m=m->next;
        ListNode* r=rev(m);
        
        int maxi=0;
        
        while(head!=NULL && r!=NULL)
        {
            maxi=max(maxi,head->val+r->val);
            head=head->next;
            r=r->next;
        }
        return maxi;
    }
};