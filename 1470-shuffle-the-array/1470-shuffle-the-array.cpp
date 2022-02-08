class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n)
    {
        vector<int> ans;
        int x=n;
       for(int i=0;i<x;i++)
       {
           ans.push_back(nums[i]); 
           ans.push_back(nums[n]);
               n++;         
       }
        return ans;
    }
};