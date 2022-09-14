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
    int res=0,n=11;
    
    void rec(TreeNode* root, vector<int> m) 
    {
        if (!root)
            return;
        
        m[root->val]++;
        
        // If we got to a leaf - check if the path can be a palindrome
        if (!root->left && !root->right)
        {
            int odd = 0;
            for (auto a : m)
                if (a % 2 == 1)
                    odd++;

            if (odd <= 1)
                res++;
        }
        
        rec(root->left, m);
        rec(root->right, m);
        m[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        vector<int> m(11,0);
       rec(root,m); 
        return res;
    }
};