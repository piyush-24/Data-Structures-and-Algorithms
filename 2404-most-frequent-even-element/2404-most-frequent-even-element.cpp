class Solution {
public:
    int mostFrequentEven(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        
        for(auto n: nums)
            mp[n]++;
        
        int ans = -1, mx = -1;
        for(auto m: mp)
        {
            if(m.first%2 == 0 && m.second >= mx)
            {
                if(m.second == mx && ans < m.first)
                    continue;
                    
                mx = m.second;
                ans = m.first;
            }
        }
        return ans;
    }
};