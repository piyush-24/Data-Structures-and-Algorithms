class Solution {
public:
    int numSub(string s) 
    {
        s+='0';
        long long x=0,j=0,n=s.size(),c=0;
        while(j<n)
        {
            if(s[j]=='0')
            {
               x+=(c*(c+1))/2; 
                c=0;
            }
            else
                c++;
            x=x%1000000007;
            j++;
        }
        
        return x;
    }
};