class Solution {
public:
    int largestValsFromLabels(vector<int>& vs, vector<int>& ls, int wanted, int limit) 
    {
        multimap<int, int> s;
        unordered_map<int, int> m;
        int res=0;
        
        for (auto i = 0; i < vs.size(); ++i)
            s.insert({vs[i], ls[i]});
        
          for (auto it = rbegin(s); it != rend(s) && wanted > 0; ++it) 
          {
            if (++m[it->second] <= limit)
            {
              res += it->first;
              --wanted;
            }
          }
      return res;
    }
};