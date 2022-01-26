class Solution {
public:
    int numSub(string s) 
    {
        s+='0';
        int mod=1e9+7;
        int i=0,j=0,n=s.size(),c=0;
        while(j<n)
        {
            if(s[j]=='0')
            {
               i=j+1;
            }
            else
                c+=(j-i+1);
                    c=c%1000000007;
            j++;
        }
        
        return c;
    }
};