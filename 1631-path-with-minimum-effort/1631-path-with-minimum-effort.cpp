#define pii pair<int,pair<int,int>>
class Solution {
public:
int minimumEffortPath(vector<vector<int>>& v) 
    {
        int n = v.size();
        int m = v[0].size();
        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));


        priority_queue<pii,vector<pii>,greater<pii>> minh;

        minh.push({0,{0,0}});

        while(minh.size())
        {
            auto temp = minh.top();
            minh.pop();
            
            auto index = temp.second;
            int dist = temp.first;

            int x = index.first;
            int y = index.second;

          for(int i = 0;i<4;i++)
          {
                int new_x = x+dx[i];
                int new_y = y+dy[i];

                if(new_x >=0 && new_x <n && new_y>=0 && new_y<m)
                {
                    int new_dist = max(dist,abs(v[new_x][new_y] - v[x][y]));
                    
                    if(dp[new_x][new_y] > new_dist)
                    {
                        dp[new_x][new_y] = new_dist;
                        minh.push({new_dist,{new_x,new_y}});
                    }
                }
            }

        }
        return dp[n-1][m-1] == INT_MAX?0:dp[n-1][m-1];        
    }
};