class Solution {
public:
    vector<int> ans;
    vector<int> findOriginalArray(vector<int>& c)
    {
        sort(c.begin(),c.end());
        int n=c.size();
        unordered_map<int,int> f;
        for(int i=0;i<n;i++)
            f[c[i]]++;
        
        for(int i=0;i<n;i++)
        {
            if(f[c[i]]==0)
                continue;
            else
            {
                ans.push_back(c[i]);
                f[c[i]]--;
                f[2*c[i]]--;
            }
            if(f[2*c[i]]<0)
            {
                ans.clear();
                break;
            }
        }
     return ans;   
    }
};