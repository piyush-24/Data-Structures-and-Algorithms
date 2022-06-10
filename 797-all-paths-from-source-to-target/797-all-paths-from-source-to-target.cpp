class Solution {
public:
    vector<vector<int>> res;
    void dfs(int node, int d, vector<vector<int>>& graph, vector<int> v)
    {
        v.push_back(node);
        if(node==d)
        {
            res.push_back(v);
            return;
        }
        
        for(auto x:graph[node])
        {
            dfs(x,d,graph,v);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<int> v;
        int n=graph.size();
        dfs(0,n-1,graph,v);
        return res;
    }
};