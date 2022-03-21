class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> res, pos(26, 0);  
    for(int i=0;i<s.length();i++)
    {
        pos[s[i]-'a']=i;
    }
        int prev=0,maxi=INT_MIN;
         for(int i=0;i<s.length();i++)
         {
             maxi=max(maxi,pos[s[i]-'a']);
             if(i==maxi)
             {
                 res.push_back(i-prev+1);
                 prev=i+1;
             }
                 
         }
        
         return res;
    }
};