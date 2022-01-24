class Solution {
public:
    bool canBeValid(string s, string l)
    {
        int open=0,close=0;
        
        if(s.size() & 1)
            return false;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || l[i]=='0')
                open++;
            else 
                close++;
                
            if(close>open)
                    return false;
        }
        
        open=close=0;
        for(int i=s.size()-1;i>=0;i--)
        {
             if(s[i]==')' || l[i]=='0')
                open++;
            else 
                close++;
                
            if(close>open)
              return false;
        }
            return true;
   
    }
};