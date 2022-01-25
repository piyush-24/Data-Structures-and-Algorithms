class Solution {
public:
    int f(vector<vector<int>>& grid, int i, int j,vector<vector<int>>& dp)
    {
        if(grid[i][j]==1)
            return 0;
        
        if(i<0 || j<0)
            return 0;
        
        if(i==0 && j==0)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int up=0,left=0;
        
        if(i>0)
            up=f(grid,i-1,j,dp);
        if(j>0)
            left=f(grid,i,j-1,dp);
        
        return dp[i][j]=(up+left);
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
          vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(grid,m-1,n-1,dp);
        
    }
};