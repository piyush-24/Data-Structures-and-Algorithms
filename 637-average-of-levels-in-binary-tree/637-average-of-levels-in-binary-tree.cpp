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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        double s=0;
        vector<double> v;
        queue<TreeNode*> q;
        q.push(root);
            while(!q.empty())
            {
                int len=q.size();
                double a=len;
                while(len--)
                {
                    TreeNode* temp=q.front();
                     q.pop();
                    s+=temp->val;
                    if(temp->left)
                    q.push(temp->left);
                    if(temp->right)
                    q.push(temp->right);
                   
                }
               v.push_back(s/a) ;
                s=0;
            }
        return v;
    }
};