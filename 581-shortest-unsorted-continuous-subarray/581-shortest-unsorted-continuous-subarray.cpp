class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        int maxi=nums[0];
        int start=-1;
        int kh=0;
        if(nums.size()==1 || is_sorted(nums.begin(),nums.end()))
            return 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<maxi)
                start=i;
            else
                maxi=nums[i];
        }
        int mini=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]>mini)
                kh=i;
            else
                mini=nums[i];
        }
      
        return start-kh+1;
    }
};