class Solution {
public:
    int minSteps(string w, string p)
    {
         int m[26]={0};
        for(auto x:w)
            m[x-'a']++;
        for(auto x:p)
            m[x-'a']--;  
       
            
        int c=0;
        for(int i=0;i<26;i++)
        {
            c+=abs(m[i]);
        }
        return c;
    }
};