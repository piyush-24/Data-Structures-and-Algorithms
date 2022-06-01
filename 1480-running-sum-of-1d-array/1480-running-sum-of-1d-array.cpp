class Solution {
public:
    vector<int> runningSum(vector<int>& nums) 
    {
        int len=nums.size();
        vector<int> v(len);
        v[0]=nums[0];
        for(int i=1;i<len;i++)
        {
            v[i]=v[i-1]+nums[i];
        }
        return v;
    }
};