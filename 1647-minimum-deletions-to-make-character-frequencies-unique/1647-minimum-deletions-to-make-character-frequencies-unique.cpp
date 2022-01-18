class Solution {
public:
    int minDeletions(string s) 
    {
        int ans = 0;
        
        unordered_set<int> usedFreqs;
        vector<int> count(26, 0);
        
        for (auto& c : s) 
            ++count[c - 'a'];
        
        
        for (int i = 0; i < 26; ++i)
        {
            while (count[i] > 0)
            {
                if (usedFreqs.find(count[i]) == usedFreqs.end()) 
                {
                    usedFreqs.insert(count[i]);
                    break;
                }
                
                --count[i];
                ++ans;
            }
        }
        
        return ans;
    }
};