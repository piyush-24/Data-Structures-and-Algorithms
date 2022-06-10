class Solution {
private:
	vector<pair<int, int>> dir = {{ -1, 0}, {1, 0}, { 0, -1}, {0, 1}, { -1, -1}, {1, -1}, { -1, 1}, { 1, 1}};
public:
    
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
        
        if(n==1 && m==1)
        {
            if(grid[0][0])
                return -1;
            else
                return 1;
        }
        
        int temp = grid[n - 1][m - 1];
		queue<pair<int, int>> q; // {i,j}
        
	   if(!grid[0][0]) 
           q.emplace(0, 0);
        
		while (!q.empty())
        {
			int sz = q.size();
			while (sz--) 
            {
				auto [r, c] = q.front();
				q.pop();
                
				for (auto &e : dir) 
                {
					int nr = r + e.first;
					int nc = c + e.second;
                    
					if (nc < 0 || nr < 0 || nc >= m || nr >= n || grid[nr][nc] != 0) 
                        continue;
                    
					grid[nr][nc] = grid[r][c] + 1;
                    q.emplace(nr, nc);
				}
			}
		}
        if(grid[n - 1][m - 1]== temp)
            return -1;
        
		return grid[n - 1][m - 1] + 1;
	}
};