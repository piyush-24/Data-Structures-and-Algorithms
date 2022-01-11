class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
    {
        int s=0;
        for(auto x:rolls)
            s+=x;
        int total=mean*(rolls.size()+n);
        if(s>total)
            return {};
        int fill=mean*(rolls.size()+n)-s;
        vector<int> v;
    
        while(n>0)
        {
            int start=fill/n;
            if(start>6 || start<1)
                return {};
                
          v.push_back(start);
            fill-=start;
            n--;
        }
      
        return v;
        
        
    }
};