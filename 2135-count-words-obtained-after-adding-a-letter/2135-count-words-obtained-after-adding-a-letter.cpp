class Solution {
public:
    int wordCount(vector<string>& sw, vector<string>& tw)
    {
       unordered_map<string, int> umap;
        for(auto it:sw)
        {
            sort(it.begin(), it.end());
            umap[it]++;
        }
        
        int ans = 0;
        for(auto it:tw)
        {
            string s;
            for(int i = 0; i < it.size(); i++)
            {
                s = it.substr(0, i) + it.substr(i+1, it.size()- i - 1);                    
                sort(s.begin(), s.end());
                if(umap.find(s) != umap.end())
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};