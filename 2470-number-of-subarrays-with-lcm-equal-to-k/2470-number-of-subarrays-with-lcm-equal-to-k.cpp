class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) 
    {
        long long int ans = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            long long int mx = nums[i], t;
            
            for(int j = i; j < nums.size(); ++j)
            {
                mx = lcm(mx, nums[j]);
                
                if(mx == k)
                {
                    ans++;
                }
                if(mx>k)
                    break;
            }
        }
        return ans;
    }
};