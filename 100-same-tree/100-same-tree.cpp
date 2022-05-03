/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void check(TreeNode* p, TreeNode* q, bool& same)
    {
        if(!p && !q)
            return;
        if(!p || !q)
        {
            same=false;
            return;
        }
        if(p->val!=q->val)
            same=false;
        check(p->left,q->left,same);
        check(p->right,q->right,same);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        bool x=true;
        check(p,q,x);
        return x;
    }
};