class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp)
    {
        if(i==n-1)
            return triangle[n-1][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int rdg=INT_MAX,ldg=INT_MAX,d=INT_MAX;
         d=  triangle[i][j]+f(i+1,j,triangle,n,dp);
        if(j+1<n)
         rdg= triangle[i][j]+f(i+1,j+1,triangle,n,dp);
        if(j-1>=0)
         ldg= triangle[i][j]+f(i+1,j-1,triangle,n,dp);
        
        return dp[i][j]=min({d,rdg,ldg});
    }
    int minFallingPathSum(vector<vector<int>>& triangle)
    {
        int n=triangle.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            vector<vector<int>> dp(n,vector<int>(n,-1));
            ans=min(ans,f(0,i,triangle,n,dp));
        }
        return ans ;
    }
};