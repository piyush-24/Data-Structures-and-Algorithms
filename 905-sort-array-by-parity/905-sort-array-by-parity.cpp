class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        if(nums.size()==1)
            return nums;
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            if(nums[low]%2!=0)
            {
                swap(nums[high],nums[low]);
                high--;
            }
            else
                low++;
                
           
        }
         return nums;
    }
};