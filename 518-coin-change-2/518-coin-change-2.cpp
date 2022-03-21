class Solution {
public:
    int f(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp)
    {
        if(amount==0)
            return 1;
        if(ind==0)
        {
            if(amount%coins[ind]==0)
                return 1;
            else
                return 0;
        }
        if(dp[ind][amount]!=-1)
            return dp[ind][amount];
        
        int take=0;
        if(amount>=coins[ind])
            take=f(ind,coins,amount-coins[ind],dp);
        
        int not_take=f(ind-1,coins,amount,dp);
        return dp[ind][amount]=take+not_take;
    }
    int change(int amount, vector<int>& coins)
    {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(n-1,coins,amount,dp);
        
    }
};