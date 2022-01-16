class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
       int i=0,j=0,n=nums.size(),c=0,res=0;
       while(j<n)
       {
           if(nums[j]==0)
               c++;
           while(c>1)
           {
               if(nums[i]==0)
                   c--;
               i++;
           }
           res=max(res,j-i+1);
           j++;
       }
        return res-1;
    }
};