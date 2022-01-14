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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode* start=NULL;
        ListNode* end=NULL;
        ListNode* temp=list1;
        
        ListNode* x=list2;
        ListNode* y=list2;
        while(y->next!=NULL)
        {
            y=y->next;
        }
        while(temp!=NULL)
        {
            if(start==NULL && a==1)
                start=temp;
            if(end==NULL && b==0)
                end=temp->next;
            temp=temp->next;
            a--;
            b--;
                
        }
        start->next=x;
        y->next=end;
        return list1;
        
    }
};