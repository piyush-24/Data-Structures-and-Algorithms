class Solution {
public:
    int countPrimeSetBits(int L, int R) 
    {
        int count=0;
        for(int i=L;i<=R;i++)
        {
            if(checkPrime(bitset<32>(i).count())) 
                count++;
        }
        return count;
    }
   
    bool checkPrime(int x)
    {
        return (x == 2 || x == 3 || x == 5 || x == 7 ||
                x == 11 || x == 13 || x == 17 || x == 19);
    }
};