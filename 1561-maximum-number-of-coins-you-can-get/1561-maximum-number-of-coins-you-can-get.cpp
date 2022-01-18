class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
        int n = piles.size();
        
        sort(piles.begin(),piles.end());
        int ans = 0;
         int i = n-2;
         n /= 3;
        
        while(n--)
        {
            ans += piles[i];
            i -= 2;
        }
        return ans;
    }
};