class Solution {
public:
    bool check(int x, int y,int n, int m)
    {
        if(x>=0 && x<n && y>=0 && y<m )
            return 1;
        else
            return 0;
    }
    
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    
    int maxDistance(vector<vector<int>>& grid) 
    {
             int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
   
        int level=1;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
            pair<int,int> p=q.front();
            q.pop();
            for(int k=0;k<4;k++)
              {
                int nx=p.first+dx[k];
                int ny=p.second+dy[k];
                if(check(nx,ny,n,m) && grid[nx][ny]==0)
                {
                    grid[nx][ny]=level;
                    q.push({nx,ny});
                }
              }
            }
            level++;
        }
        if(level==2 || level==1)
            return -1;
        return level-2;
    }
};