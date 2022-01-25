class Solution {
public:
    int f(vector<vector<int>>& grid, int i, int j,vector<vector<int>>& dp)
    {
        if(i<0 || j<0)
            return 1001;
        if(i==0 && j==0)
            return grid[0][0];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int left=grid[i][j]+f(grid,i,j-1,dp);
        int up=grid[i][j]+f(grid,i-1,j,dp);
        
        return dp[i][j]=(min(left,up));
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    dp[i][j]=grid[i][j];
                else
                {
                    int left=1001,up=1001;
                    if(i>0)
                        up=grid[i][j]+dp[i-1][j];
                    if(j>0)
                        left=grid[i][j]+dp[i][j-1];
                    
                    dp[i][j]=min(left,up);
                        
                }
            }
        }
        return dp[m-1][n-1];
    }
};