class Solution {
public:
    bool ev(int x)
    {
        int s=0;
        while(x!=0)
        {
            s+=x%10;
            x/=10;
        }
        return (s%2==0);
    }
    int countEven(int num)
    {
        int c=0;
        for(int i=2;i<=num;i++)
        {
            if(ev(i))
                c++;
        }
        return c;
    }
};