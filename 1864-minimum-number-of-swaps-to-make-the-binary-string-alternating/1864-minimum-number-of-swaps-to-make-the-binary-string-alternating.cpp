class Solution {
public:
    int f(string s, char x)
    {
        int c=0;
        for(int i=0;i<s.size();i+=2)
        {
            if(s[i]!=x)
              c++;  
        }
        return c;
    }
    int minSwaps(string s) 
    {
        int zero=0,one=0;
        for(auto x:s)
        {
            if(x=='1')
                one++;
            else
                zero++;
        }
        
        if(abs(zero-one)>1)
            return -1;
        
        if(zero>one)
            return f(s,'0');
        if(one>zero)
            return f(s,'1');
        
        return min({f(s,'0'),f(s,'1')});
    }
};