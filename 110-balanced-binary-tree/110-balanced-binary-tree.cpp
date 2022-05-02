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
    int isB(TreeNode* root, bool& flag)
    {
       if(root==NULL)
            return 0;
        int l=1+isB(root->left,flag);
        int r=1+isB(root->right,flag);
        
        if(abs(l-r)>1)
            flag=false; 
        
        return max(l,r);
    }
    bool isBalanced(TreeNode* root) 
    {
        bool flag=true;
        isB(root,flag);
        return flag;
    }
};