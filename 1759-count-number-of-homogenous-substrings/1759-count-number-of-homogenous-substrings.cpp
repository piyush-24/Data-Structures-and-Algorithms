class Solution {
public:
    int countHomogenous(string s) 
    {
        int i=0,j=0,n=s.size(),c=0;
        unordered_map<char,int> m;
        while(j<n)
        {
            m[s[j]]++;
            while(m.size()>1)
            {
                m[s[i]]--;
                if(m[s[i]]==0)
                    m.erase(s[i]);
                i++;
            }
            c+=(j-i+1);
            c=c%1000000007;
            j++;
        }
        return c;
    }
};