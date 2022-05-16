class Solution {
public:
     int largestSubset(vector<int>& a, int N)
{
   
    int bit[32] = { 0 };
    for (int i = 0; i < N; i++) 
    {
        int x = 31;
        while (a[i] > 0) 
        {
            if ((a[i] & 1) == 1)
               bit[x]++;
            
            a[i] = a[i] >> 1;
            x--;
        }
    }
    return *max_element(bit, bit + 32);
}
    int largestCombination(vector<int>& c) 
    {
        return largestSubset(c,c.size());
    }
};