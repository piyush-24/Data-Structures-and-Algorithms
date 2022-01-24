class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int l=0,r=nums.size()-1,res=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]==target)
            {
                res=mid;
                r=mid-1;
            }
            else if(nums[mid]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        
        vector<int> x;
        x.push_back(res);
        
        l=0,r=nums.size()-1,res=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]==target)
            {
                res=mid;
                l=mid+1;
            }
            else if(nums[mid]>target)
                r=mid-1;
            else
                l=mid+1;
        }
       x.push_back(res);
        return x;
    }
};