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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode *dummy = new ListNode(0);
        dummy->next=head;
        ListNode* pre=dummy;
        ListNode* left_pre=NULL;
        
        //till left index
        for(int i=0;i<(left);i++)
        {
            left_pre=pre;
            pre=pre->next;
        }
        
        // reverse
        
        ListNode* curr=pre;
        ListNode* prev=left_pre;
        
        for(int i=left;i<=right;i++)
        {
           ListNode* forward=curr->next;
           curr->next=prev;
            prev=curr;
            curr=forward;
           
        }
        
        //connect
        left_pre->next=prev;
        pre->next=curr;
            return dummy->next;
        
    }
};