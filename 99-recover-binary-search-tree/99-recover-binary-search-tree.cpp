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
// 1 3 2 4
class Solution {
public:
    void check(TreeNode* root, TreeNode*& first, TreeNode*& second, TreeNode*& prev)
    {
        if(!root)
            return;
        check(root->left,first,second,prev);
        if(first==NULL && prev->val>root->val)
            first=prev;
        if(first!=NULL && prev->val>root->val)
            second=root;
        prev=root;
        check(root->right,first,second,prev);  
    }
    void recoverTree(TreeNode* root) 
    {
        TreeNode* first=NULL;
        TreeNode* second=NULL;
        if(!root)
            return;
        TreeNode* prev=new TreeNode(INT_MIN);
        check(root,first,second,prev);
        swap(first->val,second->val);
    }
};