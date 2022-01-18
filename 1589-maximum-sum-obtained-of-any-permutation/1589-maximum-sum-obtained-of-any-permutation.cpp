#define ll long long int
const int mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Solution {
public:
    int maxSumRangeQuery(vector<int>& a, vector<vector<int>>& b) {
        IOS;
        ll i,n=a.size();
        vector<ll> prefix(n+2,0);
        
        for(auto v:b)
        {
            prefix[v[0]]++;
            prefix[v[1]+1]--;
        }
        
        for(i=1;i<n;i++)
            prefix[i]+=prefix[i-1];
            
        sort(prefix.begin(),prefix.end(),greater<ll>());
        sort(a.begin(),a.end(),greater<int>());
        
        ll k=0,s=0;
        
        for(i=0;i<n;i++,k++)
        {
            if(prefix[i])
                s=(s+a[k]*prefix[i])%mod;    
            else
                break;
        }
        
        return s;
    }
};