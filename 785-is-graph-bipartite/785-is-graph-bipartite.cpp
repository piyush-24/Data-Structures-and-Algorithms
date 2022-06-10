class Solution {
private:
    bool BipartiteBFS(int src, vector<vector<int>>& graph, vector<int> &color) 
    {
        
        color[src] = 1;
        
        queue<int> q;
        q.push(src);
        
        while(q.empty() == false)
        {
            int node = q.front();
            q.pop();
            
            for(auto nbr : graph[node])
            {
                if(color[nbr] == color[node])
                    return false;
                else 
                {
                    if(color[nbr] == -1)
                    {
                        color[nbr] = 1 - color[node];
                        q.push(nbr);
                    }
                }
            }
        }
        
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color(n, -1);
        
        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                if(BipartiteBFS(i, graph, color) == false) 
                    return false;
            }
        }
        
        return true;
    }
};