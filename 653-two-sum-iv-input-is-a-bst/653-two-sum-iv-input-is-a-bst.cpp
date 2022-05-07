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
    void check(TreeNode* root, vector<int>& v)
    {
        if(!root)
            return;
        check(root->left,v);
        v.push_back(root->val);
        check(root->right,v);
    }
    bool findTarget(TreeNode* root, int k)
    {
        vector<int> v;
        check(root,v);
        int i=0,j=v.size()-1;
        while(i<j)
        {
            if(v[i]+v[j]==k)
                return true;
            if(v[i]+v[j]>k)
                j--;
            else
                i++;    
        }
        return false;
    }
};