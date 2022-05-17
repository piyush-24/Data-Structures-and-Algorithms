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
    void check(TreeNode* cloned, TreeNode*& target)
    {
        if(!cloned)
            return;
        check(cloned->left,target);
        if(cloned->val==target->val)
        {
            target=cloned;
            return;
        }
        check(cloned->right,target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        check(cloned,target);
        return target;
    }
};