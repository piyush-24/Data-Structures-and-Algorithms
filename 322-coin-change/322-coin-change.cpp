class Solution {
public:
    int f(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp)
    {
        if(amount==0)
            return 0;
        if(ind==0)
        {
            if(amount%coins[ind]==0)
                return amount/coins[ind];
            else
                return INT_MAX-5;
        }
        if(dp[ind][amount]!=-1)
            return dp[ind][amount];
        
        int take=INT_MAX-5;
        if(amount>=coins[ind])
            take=1+f(ind,coins,amount-coins[ind],dp);
        
        int not_take=f(ind-1,coins,amount,dp);
        return dp[ind][amount]=min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount)
    {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int mc= f(n-1,coins,amount,dp);
        if(mc==INT_MAX-5)
            return -1;
        else
            return mc;
    }
};