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
class Solution
{
    int findHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int leftChild = findHeight(root->left);
        int rightChild = findHeight(root->right);
        
        return max(leftChild, rightChild) + 1;
    }
    void generateTree(vector<vector<string>> &ans, TreeNode* root, int level, int l, int r)
    {
        if(!root)
            return ;
        
        int mid = (r+l)/2;
        ans[level][mid] = to_string(root->val);
        generateTree(ans, root->left,level+1, l, mid-1);
        generateTree(ans, root->right, level+1, mid+1, r);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) 
    {
        int height = findHeight(root);  //find MAX height of a tree
        int width = pow(2,height) - 1;
        vector<vector<string>> ans(height, vector<string> (width, ""));
        generateTree(ans, root, 0, 0, width);
        return ans;
    }
};