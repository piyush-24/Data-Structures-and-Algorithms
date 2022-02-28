class Solution {
public:
    int prefixCount(vector<string>& w, string p) 
    {
        int c=0;
       for(auto x:w)
       {
           string s=x;
           int xe=s.find(p);
           if(xe==0)
               c++;
       }
        return c;
    }
};