class Solution {
public:
    int len=INT_MAX;
    int jp(int index, vector<int>& nums, vector<int>& dp)
    {
        
        if(index>=nums.size()-1)
            return 0;
        
        if(dp[index]!=INT_MAX-1)
            return dp[index];
        
        for(int i=1;i<=nums[index];i++)
        {
            dp[index]=min(dp[index],1+jp(index+i,nums,dp));
        }
        return dp[index];
    }
    int jump(vector<int>& nums)
    {
        vector<int> dp(nums.size(),INT_MAX-1);
        return jp(0,nums,dp);

    }
};