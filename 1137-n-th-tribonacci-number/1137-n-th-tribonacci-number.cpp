class Solution {
public:
  
     int tribonacci(int n)
    {
       if(n==0)
           return 0;
         if(n==1)
             return 1;
         if(n==2)
             return 1;
       int prev1=0,prev2=0,prev3=0,res=0;
       prev1=0;
       prev2=1;
       prev3=1;
       for(int i=3;i<=n;i++)
       {
           res=prev3+prev2+prev1;
           prev1=prev2;
           prev2=prev3;
           prev3=res;
       }
        return res;
    }
};