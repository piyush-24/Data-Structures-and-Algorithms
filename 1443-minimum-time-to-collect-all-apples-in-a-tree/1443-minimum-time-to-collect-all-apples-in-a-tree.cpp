class Solution {
public:
    vector<vector<int>> adjList;
    int dfs(vector<bool>& hasApple,int node,int d,int prev)
    {
        int res=0, temp;
        for(auto& it:adjList[node])
        {
            if(it!=prev)
            {
                temp=dfs(hasApple, it, d+1, node);
                
                if(temp>0)
                {
                    
                    res+=(temp-d);
                }
            }
        }
        
        if(res)                                        //return res||hasApple[node]?res+d:0;
            return res+d;
        else
        {
            if(hasApple[node]==true)
                return (res+d);
            else
                return 0;
        }
        
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        adjList.resize(n);
        for(vector<int> &e:edges)
        {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
            
        return dfs(hasApple,0,0,-1)*2;     //Result is doubled the distance travelled as per our observation.
    }
};