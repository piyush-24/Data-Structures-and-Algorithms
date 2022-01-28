class Solution {
public:
    int numberOfArrays(vector<int>& c, int lower, int upper) 
    {
         long long count = 0;
        int  maxi = 0, mini = 0;
     for(int i: c)
     {
         count += i;
      if(count>maxi)
          maxi=count;
      if(count<mini)
          mini=count;
    }
        return max(0, (upper-lower) - (maxi-mini)+1);
    }
};