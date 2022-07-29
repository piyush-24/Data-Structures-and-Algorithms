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
    TreeNode* check(vector<int>& postorder, vector<int>& inorder,int& curr,int ins,int ine,unordered_map<int,int>& m)
    {
        if(ins>ine)
            return NULL;
        
        TreeNode* root=new TreeNode(postorder[curr]);
        int mid=m[postorder[curr]];
        curr--;
        
        root->right=check(postorder,inorder,curr,mid+1,ine,m);
        root->left=check(postorder,inorder,curr,ins,mid-1,m);
        
        return root;   
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        
        int curr=postorder.size()-1,ins=0,ine=inorder.size()-1;
        return check(postorder,inorder,curr,ins,ine,m);   
    }   
};