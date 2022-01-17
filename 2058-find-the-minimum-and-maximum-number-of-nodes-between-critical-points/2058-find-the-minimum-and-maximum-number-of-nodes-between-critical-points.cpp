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
     void pr(vector<int> v)
    {
        for(auto x:v)
        cout<<x<<" ";
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head)
    {
        if(head->next->next==NULL)
            return {-1,-1};
        
        ListNode* prev=head;
        ListNode* temp=head->next;
        ListNode* nxt=head->next->next;
        int c=1;
        vector<int> v;
        while(nxt!=NULL)
        {
            if((prev->val>temp->val && nxt->val>temp->val) || (prev->val<temp->val && nxt->val<temp->val) )
                v.push_back(c);
            prev=temp;
            nxt=nxt->next;
            temp=temp->next;
            c++;
        }
        if(v.size()<=1)
            return {-1,-1};
        
        int mini=INT_MAX;
        for(int i=1;i<v.size();i++)
        {
            mini=min(mini,abs(v[i]-v[i-1]));
        }
        return {mini,v[v.size()-1]-v[0]};
        
    }
};