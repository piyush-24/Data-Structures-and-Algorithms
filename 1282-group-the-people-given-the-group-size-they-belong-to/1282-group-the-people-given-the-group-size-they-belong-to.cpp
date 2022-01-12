class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs)
    {
        vector<vector<int>> v;
        unordered_map<int, vector<int>> m;
        for(int i=0;i<gs.size();i++)
            m[gs[i]].push_back(i);
        
        for(auto it:m)
        {
           int x=it.second.size()/it.first;
            while(x)
            {
                int z=it.first;
                 vector<int> temp;
                while(z)
                {
                    temp.push_back(it.second.back());
                    it.second.pop_back();
                    z--;
                }
                v.push_back(temp);
                x--;
            }
        }
        return v;
    }
};