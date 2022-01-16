class Solution {
public:
    int equalSubstring(string s, string t, int mc) 
    {
        int i=0,j=0,n=s.size(),sum=0,res=0;
        while(j<n)
        {
            sum+=abs(s[j]-t[j]);
            while(sum>mc)
            {
                sum-=abs(s[i]-t[i]);
                i++;
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};