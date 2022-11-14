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
    int find(vector<int>& v)
    {
        vector<pair<int,int>> v1;
            int c=0;
        for(int i=0;i<v.size();i++)
            v1.push_back({v[i],i});
        
        sort(begin(v1),end(v1));
        for(int i=0;i<v1.size();i++)
        {
            pair<int,int> p=v1[i];
            while(p.second!=i)
            {
                swap(v1[p.second],p);
                c++;
            }
                
        }
        return c;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int c=0;
        while(!q.empty())
        {
            int len=q.size();
            vector<int> v;
            while(len--)
            {
                TreeNode* top=q.front();
                q.pop();
                
                if(top->left)
                {
                    q.push(top->left);
                    v.push_back(top->left->val);
                }
                if(top->right)
                {
                    q.push(top->right);
                    v.push_back(top->right->val);
                }
            }
            c+=find(v);
            
        }
        return c;
    }
};