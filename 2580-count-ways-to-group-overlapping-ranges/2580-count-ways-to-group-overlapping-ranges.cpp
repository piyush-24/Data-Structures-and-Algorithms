class Solution {
public:
    
    int countWays(vector<vector<int>>&v)
    {
        long long cnt=1,i=0,n=v.size(),mod=1e9+7;
        sort(v.begin(),v.end());
        int mergesize=0;
        int first = v[0][0], second = v[0][1];
        for(i=1;i<n;i++)
        {
            if(v[i][0]<=second)
                second = max(second,v[i][1]);
            else
            {
                mergesize++;
                first=v[i][0];
                second=v[i][1];
            }
        }
        mergesize++;
        for(i=0;i<mergesize;i++)
            cnt=(cnt*2)%mod;
        
        return cnt;
    }
};