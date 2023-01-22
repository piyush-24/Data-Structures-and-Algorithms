class Solution {
public:
    int alternateDigitSum(int n) {
        int i=1,s=0;
        vector<int> v;
        while(n!=0)
        {
            v.push_back(n%10);
            n/=10;
        }
       reverse(v.begin(), v.end());
      for(int i=0;i<v.size();i++)
      {
          if(i%2==0)
              s+=v[i];
          else
              s+=(-1*v[i]);
      }
        return s;
    }
};