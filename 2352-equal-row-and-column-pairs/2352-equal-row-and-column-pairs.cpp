class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int n=grid.size();
        
        unordered_map<string, int> st;
        
        for(int i=0;i<n;i++)
        {
            string s="";
            for(int j=0;j<n;j++)
            {
                s+=to_string(grid[i][j])+"#";
            }
           st[s]++;
        }
        int c=0;
         for(int i=0;i<n;i++)
        {
            string s="";
            for(int j=0;j<n;j++)
            {
                s+=to_string(grid[j][i])+"#";
            }
            if(st[s]>0)
                c+=(st[s]);
        }
       return c; 
    }
};