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
    void check(TreeNode* root, int targetSum, bool& ch, int s)
    {
        if(!root)
            return ;
        s+=root->val;
        if(!root->left && !root->right && targetSum==s)
            ch=true;
        check(root->left,targetSum,ch,s);
        check(root->right,targetSum,ch,s);
    }
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        bool x=false;
        int s=0;
        check(root,targetSum,x,s);
        return x;
    }
};