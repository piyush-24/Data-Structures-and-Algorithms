class Solution {
public:
    int mySqrt(int x) 
    {
        double start=1;
        double end=x;
        double eps=1e-5;
        
        while((end-start)>eps)
        {
            double mid=start+(end-start)/2;
            if((mid*mid)>x)
             end=mid;
                else
             start=mid;      
        }
        int y=end;
        return y;
    }
};