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
    TreeNode* check(vector<int>& preorder, vector<int>& inorder,int& curr,int ins,int ine,unordered_map<int,int>& m)
    {
        if(ins>ine)
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[curr]);
        int mid=m[preorder[curr]];
        curr++;
        
        root->left=check(preorder,inorder,curr,ins,mid-1,m);
        root->right=check(preorder,inorder,curr,mid+1,ine,m);
        
        return root;   
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
         unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        
        int curr=0,ins=0,ine=inorder.size()-1;
        return check(preorder,inorder,curr,ins,ine,m);
        
    }
};