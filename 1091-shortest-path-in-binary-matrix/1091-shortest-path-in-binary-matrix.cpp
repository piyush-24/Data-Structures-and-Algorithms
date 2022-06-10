class Solution {
public:
    int n;
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};
   
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        n = grid.size();
        
        if (grid[0][0]==1 || grid[n-1][n-1]) 
            return -1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1 ;
        int st=1;
        while(!q.empty()) 
        {
            int sz=q.size();
            while(sz--)
            {
                int i= q.front().first;
                int j = q.front().second;
           
                q.pop();
                if (i == n- 1 && j == n-1)
                {
                    return st;
                }

                for(int k= 0 ;k <8;k++)
                {
                    int x = i + dx[k];
                    int y = j +dy[k];

                    if(x>=0 && x <n && y >=0 && y <n && grid[x][y] == 0 ) 
                    {
                        grid[x][y] = 1;
                        q.push({x,y});
                    }
                }
            }
          st++;
        }
        return -1;
    }
};