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
    int height(TreeNode* root, unordered_map<int, int>& l, unordered_map<int, int>& r)
    {
        if(!root)
            return 0;
        
        int lh=height(root->left,l,r);
        int rh=height(root->right,l,r);
        
        l[root->val]=lh;
        r[root->val]=rh;
        
        return 1+max(lh,rh);
    }
    void solve(TreeNode* root, int maxi, unordered_map<int, int>& l, unordered_map<int, int>& r, unordered_map<int, int>& h,int d)
    {
        if(!root)
            return ;
        
        h[root->val]=maxi;
        
        solve(root->left, max(maxi, d+r[root->val])  ,l, r, h, d+1);
        solve(root->right, max(maxi, d+l[root->val]) ,l, r, h, d+1);
            
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries)
    {
        unordered_map<int, int> l,r,h;
        height(root,l,r);
        solve(root->left,  r[root->val],l,r,h,1);
        solve(root->right, l[root->val],l,r,h,1);
        
        vector<int> v;
        for(auto x:queries)
            v.push_back(h[x]);
        
        return v;
    }
};