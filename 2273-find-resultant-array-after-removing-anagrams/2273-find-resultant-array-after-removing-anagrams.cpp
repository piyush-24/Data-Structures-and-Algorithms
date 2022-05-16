class Solution {
public:
    vector<string> removeAnagrams(vector<string>& w) 
    {
        set<string> st;
        vector<string> v;
        int i=0,j=0;
       
       while(j<w.size())
       {
           string m1=w[i],m2=w[j];
           sort(begin(m1),end(m1));
           sort(begin(m2),end(m2));
           if(m1==m2)
               j++;
           else
           {
               v.push_back(w[i]);
               i=j;
           }
       }
         v.push_back(w[i]);
        return v;
    }
};