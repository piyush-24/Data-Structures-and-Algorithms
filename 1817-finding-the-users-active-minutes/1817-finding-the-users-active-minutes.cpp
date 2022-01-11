class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) 
    {
        int len=logs.size();
        vector<int> v(k,0);
        unordered_map<int,unordered_set<int>> m;
        for(auto x:logs)
        {
            m[x[0]].insert(x[1]);
        }
        
        for(auto it:m)
        {
            v[it.second.size()-1]++;
        }
        return v;
    }
};