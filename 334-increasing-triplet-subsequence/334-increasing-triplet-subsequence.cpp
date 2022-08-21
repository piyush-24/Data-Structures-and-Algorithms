class Solution {
public:
    
 bool increasingTriplet(vector<int>& nums)
 {
     int one=INT_MAX, two=INT_MAX;
     for(auto x:nums)
     {
         if( one > x)
             one=x;
         else if( x > one && x < two)
             two=x;
         else if( x > two)
             return true;
     }
     return false;
 }
 
};