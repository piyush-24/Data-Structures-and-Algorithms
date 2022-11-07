class Solution {
public:
    int maximum69Number (int num) 
    {
        int i,firstsix=-1;
        int n=num;
        for(i=0;n>0;i++)
        {
            if(n%10==6)
                firstsix=i;
            n=n/10;
        }
        return num+(3*pow(10,firstsix));
    }
};