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
    ListNode* deleteDuplicates(ListNode* head)
    {
         ListNode* newn=new ListNode(0);
         newn->next=head;
         ListNode* temp=head;
         ListNode* prev=newn;
        
        while(temp!=NULL && temp->next!=NULL)
        {
            bool f=false;
            while(temp->next!=NULL && temp->val==(temp->next)->val)
            {
                temp=temp->next;
                f=true;
            }
            
            if(f)
                prev->next=temp->next;
            else 
            prev=temp;
            
            temp=temp->next;
        }
        return newn->next;
    }
};