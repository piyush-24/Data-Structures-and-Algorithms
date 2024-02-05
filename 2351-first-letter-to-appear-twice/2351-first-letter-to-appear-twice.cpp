class Solution {
public:
    char repeatedCharacter(string s) {
        
        unordered_map<char, pair<int,int>> mp;
        
        for(int i=0;i<s.size();i++)
        {
            
           char it=s[i];
           mp[it].first++;
            
           if(mp[it].first==2)
             mp[it].second=i;
        }
        
        int idx=INT_MAX;
        for(auto it:mp)
        {
          if(it.second.first > 1)
          {
              idx=min(idx, it.second.second);
          }
        }
        return s[idx];
    }
};


