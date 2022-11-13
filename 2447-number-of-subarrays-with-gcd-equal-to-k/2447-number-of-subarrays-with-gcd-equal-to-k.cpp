class Solution {
public:
long long int gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b); 
}
    int subarrayGCD(vector<int>& nums, int k) {
         long long int ans = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            long long int mx = nums[i], t;
            
            for(int j = i; j < nums.size(); ++j)
            {
                mx = gcd(mx, nums[j]);
                
                if(mx == k)
                {
                    ans++;
                }
               
            }
        }
        return ans;
        
    }
};