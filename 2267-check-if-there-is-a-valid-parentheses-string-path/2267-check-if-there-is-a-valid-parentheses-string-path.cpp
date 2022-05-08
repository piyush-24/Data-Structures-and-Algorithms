class Solution {
public:
    int dp[105][105][205];
    bool isValid(int i, int j, vector<vector<char>>& grid)
    {
        return (i>=0 && i<grid.size() && j>=0 && j<grid[0].size());
    }
    bool f(int i, int j, vector<vector<char>>& grid, int bal)
    {
        int bal1=bal;
        
        if(bal<0)
            return false;
        
        if(dp[i][j][bal]!=-1)
            return dp[i][j][bal];
        
        
            
        if(grid[i][j]=='(')
            bal1++;
        else
            bal1--;
        
        
        int n=grid.size(), m=grid[0].size();
        
        if(i==n-1 && j==m-1)
            return (bal1==0);
        
        bool l=false,d=false;
        if(isValid(i,j+1,grid))
            l=f(i,j+1,grid,bal1);
        if(isValid(i+1,j,grid))
            d=f(i+1,j,grid,bal1);
        
        return dp[i][j][bal]=(l || d);
            
    }
    bool hasValidPath(vector<vector<char>>& grid) 
    {
        for(int i=0;i<105;i++)
            for(int j=0;j<105;j++)
                for(int k=0;k<205;k++)
                       dp[i][j][k]=-1;
        
        return f(0,0,grid,0);
    }
};