class Solution {
public:
    long long f(int ind, vector<vector<int>>& questions, vector<long long>& dp)
    {
        if(ind==questions.size()-1)
            return questions[ind][0];
        
        if(ind>=questions.size())
            return 0;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        long long take=questions[ind][0]+ f(ind+questions[ind][1]+1, questions,dp);
        
        long long not_take=0+f(ind+1,questions,dp);
        
        return dp[ind]=max(take,not_take);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(),-1);
        return f(0,questions,dp);
    }
};