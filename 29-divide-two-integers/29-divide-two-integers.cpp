class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        if(dividend==INT_MIN && divisor==-1)
            return INT_MAX;
        
        if(dividend==INT_MIN && divisor==INT_MIN)
            return 1;
        if(dividend<0 && divisor<0)
        {
            return (abs(dividend)/abs(divisor));
        }
        else if(dividend<0 || divisor<0)
        {
            return -(abs(dividend)/abs(divisor));
        }
        else
        {
            return (abs(dividend)/abs(divisor));
        }
    }
};