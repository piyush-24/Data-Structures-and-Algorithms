class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int start=0, end=nums.size()-2;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==nums[mid^1]) // 1 1 2 2 3 3 4 4 5 6 6
                start=mid+1;
            else
                end=mid-1;
        }
        return nums[start];
    }
};