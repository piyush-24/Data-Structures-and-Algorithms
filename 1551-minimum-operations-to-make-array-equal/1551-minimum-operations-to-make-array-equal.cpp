class Solution {
public:
    int minOperations(int n)
    {
        int s=0;
        if(n%2==0)
        {
            for(int i=1;i<n;i+=2)
                s+=i;
        }
        else
        {
            for(int i=2;i<n;i+=2)
                s+=i;
        }
        return s;
    }
};