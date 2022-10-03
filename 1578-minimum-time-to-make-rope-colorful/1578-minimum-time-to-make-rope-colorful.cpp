class Solution {
public:
    int minCost(string c, vector<int>& n)
    {
        int s=0,sum=0,maxi=0;
      for(int i=0;i<c.size();i++)
      {
          if(i>0 && c[i]!=c[i-1])
          {
               s+=(sum-maxi);
                sum=maxi=0;
          }
         sum+=n[i]; 
         maxi=max(maxi,n[i]);
      }
        s+=(sum-maxi);
        return s;
    }
};