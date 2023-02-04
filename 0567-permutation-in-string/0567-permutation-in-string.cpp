class Solution {
public:
    bool checkInclusion(string p, string s) 
    {
         vector<int> sv(26),pv(26),res;
         if(s.size() < p.size())
           return false;
        
        bool flag=false;
        
        for(int i = 0; i < p.size(); ++i)
        {
            ++pv[p[i]-'a'];
            ++sv[s[i]-'a'];
        }
        
        if(pv == sv)
           flag=true;
        
         for(int i = p.size(); i < s.size(); ++i) 
        {
             // window extends one step to the right. counter for s[i] is incremented 
            ++sv[s[i]-'a'];
            
            // since we added one element to the right, 
            // one element to the left should be discarded. 
            //counter for s[i-p.size()] is decremented
            --sv[s[i-p.size()]-'a']; 

            // if after move to the right the anagram can be composed, 
            // add new position of window's left point to the result 
            if(pv == sv)  
               flag=true;
        }
        return flag;
    }
};