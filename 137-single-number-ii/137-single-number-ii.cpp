class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int ans=0;
        for(int i=0;i<=31;i++)
        {
            int c=0;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j] & 1<<i)
                    c++;
            }
            if(c%3!=0)
                ans+=(1<<i);
        }
        return ans;
    }
};