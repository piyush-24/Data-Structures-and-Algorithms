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
        
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        grid[0][0] = 1 ;
        
        while(!q.empty()) 
        {
            int i= q.front().first.first;
            int j = q.front().first.second;
            int st = q.front().second;
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
                    q.push({{x,y},st+1});
                }
            }
        }
        return -1;
    }
};