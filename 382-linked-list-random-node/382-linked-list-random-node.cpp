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
   ListNode* duphead;
    int len;
    Solution(ListNode* head)
    {
        len=0;
        duphead=head;
        while(head!=NULL)
        {
            head=head->next;
            len++;
        }
    }
    
    int getRandom() {
        int noN=rand()%len;
        ListNode* ans=duphead;
        while(noN>0)
        {
            noN--;
            ans=ans->next;
        }
        return ans->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */