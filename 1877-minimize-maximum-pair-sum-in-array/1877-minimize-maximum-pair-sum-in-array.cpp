class Solution {
public:
    int minPairSum(vector<int>& nums)
    {
        sort(begin(nums),end(nums));
        int n=nums.size(),maxi=0,s=0;
        for(int i=0;i<n/2;i++)
        {
            maxi=max(nums[i]+nums[n-i-1],maxi);
        }
        return maxi;
    }
};