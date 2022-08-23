/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*,TreeNode*> m;
        unordered_map<TreeNode*,bool > visited;
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left)
            {
                m[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                m[temp->right]=temp;
                q.push(temp->right);
            }       
        }
        q.push(target);
        while(!q.empty())
        {
           
            if(k==0)
                break;
            int len=q.size();
            while(len--)
            {
               TreeNode* temp=q.front();
                q.pop(); 
                visited[temp]=true;
                if(temp->left && !visited[temp->left])
                    q.push(temp->left);
                if(temp->right && !visited[temp->right])
                    q.push(temp->right);
                if(m[temp] && !visited[m[temp]])
                    q.push(m[temp]);
            }
            k--;
        }
        vector<int> v;
        while(!q.empty())
        {
            v.push_back(q.front()->val);
            q.pop();
        }
        return v;
    }
};