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
    void check(TreeNode* root, map<int,map<int,multiset<int>>>& m, int d, int s)
    {
        queue<pair<pair<int,int>,TreeNode*>> q;
        q.push({{d,s},root});
        while(!q.empty())
        {
            pair<pair<int,int>,TreeNode*> temp=q.front();
            q.pop();
            
            TreeNode* temp1=temp.second;
            
            pair<int,int> c=(temp.first);
            int vt=c.second;
            int hd=c.first;
            
            m[hd][vt].insert(temp1->val);
            
            if(temp1->left)
                q.push({{hd-1,vt+1},temp1->left});
            
            if(temp1->right)
                q.push({{hd+1,vt+1},temp1->right});
            
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        vector<vector<int>> vect;
        vector<int> v;
        map<int,map<int,multiset<int>>> m;
        check(root,m,0,0);
        
        for(auto i:m)
        {
            for(auto n:i.second)
            {
                for(auto x:n.second)
                    v.push_back(x);
            }
            vect.push_back(v);
            v.clear();
            
        }
        return vect;
    }
};