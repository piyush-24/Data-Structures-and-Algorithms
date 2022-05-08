class Solution {
public:
    string largestGoodInteger(string s)
    {
        int i=0,j=0,k=3,n=s.size();
        string ans;
        map<int,int> m;
        while(j<n)
        {
            m[s[j]]++;
            if(j-i+1>=k)
            {
                if(j-i+1==k && m.size()==1)
                {
                    string x=s.substr(i,3);
                    ans=max(ans,x);
                }
                while(m.size()>1)
                {
                    m[s[i]]--;
                    if(m[s[i]]==0)
                        m.erase(s[i]);
                    
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};