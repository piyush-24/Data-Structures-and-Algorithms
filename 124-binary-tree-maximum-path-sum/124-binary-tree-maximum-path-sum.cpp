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
    int f(TreeNode* root, int &maxi)
    {
        if(root==NULL)
            return 0;
        
        int l=f(root->left,maxi);
        int r=f(root->right,maxi);
        
        maxi=max({maxi,root->val+l+r});
        
        return max(0,root->val+max({l,r}));
  
    }
    int maxPathSum(TreeNode* root)
    {
        int maxi=-10005;
        f(root,maxi);
        return maxi;
    }
};