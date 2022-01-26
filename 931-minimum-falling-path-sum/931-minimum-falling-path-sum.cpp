class Solution {
public:
   
    int minFallingPathSum(vector<vector<int>>& triangle)
    {
        int n=triangle.size();
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
            dp[n-1][i]=triangle[n-1][i];
        
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                 int rdg=INT_MAX,ldg=INT_MAX,d=INT_MAX;
                 d=  triangle[i][j]+dp[i+1][j];
                
                if(j+1<n)
                 rdg= triangle[i][j]+dp[i+1][j+1];
                
                if(j-1>=0)
                 ldg= triangle[i][j]+dp[i+1][j-1];

                 dp[i][j]=min({d,rdg,ldg});
            }
            
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
            ans=min(ans,dp[0][i]);
        return ans ;
    }
};