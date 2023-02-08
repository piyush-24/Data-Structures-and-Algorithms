class Solution {
public:
    int solve(int ind,vector<int>& nums,vector<int>& dp)
    {  
        if(ind>=nums.size()-1)
            return 0;
        
        if(dp[ind]!=1e5)
            return dp[ind];
        
        for(int i=1;i<=nums[ind];i++)
        {
            dp[ind]=min(dp[ind],1+solve(ind+i,nums,dp));
        }
        return dp[ind];
    }
    int jump(vector<int>& nums) 
    {
         int n=nums.size();
         vector<int> dp(n+1,1e5);
         return solve(0,nums,dp);
        
    }
};