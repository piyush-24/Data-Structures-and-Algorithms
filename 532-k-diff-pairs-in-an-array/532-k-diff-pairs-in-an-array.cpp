class Solution {
public:
    int findPairs(vector<int>& nums, int k)
    {
        unordered_map<int,int> m;
        int c=0;
        for(auto x:nums)
            m[x]++;
        for(auto x:m)
        {
            if(k!=0)
            {
               if(m.find(x.first-k)!=m.end())
                c++;
            }
            else
            {
                if(x.second>1)
                    c++;
            }
            
        }
        return c;
    }
};