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
    void ino(TreeNode* root, vector<int>& list)
    {
        if(root==NULL)
            return ;
        ino(root->left,list);
    
        list.push_back(root->val);
        
        ino(root->right,list);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        vector<int> list1, list2;
        ino(root1, list1);
        ino(root2, list2);
        
        int len1=list1.size();
        int len2=list2.size();
        
        int i=0,j=0;
        vector<int> x;
        while(i<len1 && j<len2)
        {
            if(list1[i]>list2[j])
            {
                x.push_back(list2[j]);
                j++;
            }
            else
            {
                x.push_back(list1[i]);
                i++;
            }
        }
        while(i<len1)
        {
            x.push_back(list1[i]);
                i++;
        }
        while(j<len2)
        {
           x.push_back(list2[j]);
                j++;  
        }
        
       return x; 
    }
};