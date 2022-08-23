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
    void check(TreeNode* root, int targetSum,vector<vector<int>>& v,vector<int>& c, int& s)
    {
        if(!root)
            return;
        s+=root->val;
        c.push_back(root->val);
        if(!root->left && !root->right && s==targetSum)
            v.push_back(c);
        check(root->left,targetSum,v,c,s);
        check(root->right,targetSum,v,c,s);
        
        s-=root->val;
        c.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>> v;
        vector<int> c;
        int s=0;
        check(root,targetSum,v,c,s);
        return v;
    }
};