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
    void check(TreeNode* root, int& k, int& x)
    {
        if(!root)
            return ;
        check(root->left,k,x);
        k--;
        if(k==0)
        x=root->val;  
        check(root->right,k,x);  
    }
    int kthSmallest(TreeNode* root, int k)
    {
        int x=-1;
        check(root,k,x);
        return x;
    }
};