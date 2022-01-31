class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int left=0,right=0;
        for(auto x:nums)
            right+=x;
        int l=0,r=0;
        for(int i=0;i<nums.size();i++)
        {
            left+=nums[i];
            l=left-nums[i];
            r=right-left;
            
            if(r==l)
                return i;
            
        }
        return -1;
    }
};