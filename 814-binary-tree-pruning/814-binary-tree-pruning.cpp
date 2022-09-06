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
    int x(TreeNode* root)
    {
         if(!root->left && !root->right)
            return root->val;
        
        int l=0,r=0;
        if(root->left)
        l=x(root->left);
        
        if(root->right)
        r=x(root->right);
        
        if(l==0)
            root->left=NULL;
        if(r==0)
            root->right=NULL;
        
        return (root->val+l+r);
    }
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode* res=new TreeNode(0);
        res->left=root;
        x(res);
       return res->left;
        
    }
};