class Solution {
public:
     int atmost(vector<int>& nums, int k)
    {
         if(k<0)
             return 0;
         int j=0,i=0,n=nums.size();
         int s=0,c=0;
        while(j<n)
        {
           k-=nums[j];
           while(k<0)
           {
              k+=nums[i];
                   i++;
           }
            c+=j-i+1;
            j++;
        }
        return c;
    }
    int numSubarraysWithSum(vector<int>& nums, int k)
    {
       return(atmost(nums,k)-atmost(nums,k-1));
    }
};