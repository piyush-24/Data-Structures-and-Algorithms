class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int pos=0,ans=0;
        while(n)
        {
            if(n%2)
            {
                ans+=(1<<(31-pos));    
            }
            n=n>>1;
            pos++;
        }
        return ans;
    }
};