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
    void check(TreeNode* root, TreeNode*& prev,bool& x)
    {
        if(!root)
            return;
        check(root->left,prev,x);
        if(prev!=NULL && root->val<=prev->val)
            x=false;
        prev=root;
        check(root->right,prev,x);
    }
    bool isValidBST(TreeNode* root)
    {
        bool x=true;
        TreeNode* prev=NULL;
        
        check(root,prev,x);
        return x;
    }
};