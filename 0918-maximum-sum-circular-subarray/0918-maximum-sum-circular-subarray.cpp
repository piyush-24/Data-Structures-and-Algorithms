class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int sum=nums[0], prev_max=nums[0], prev_min=nums[0], maxi=nums[0], mini=nums[0] ;
        
        for(int i=1;i<nums.size();i++)
        {
            sum+=nums[i];
            
            prev_max=max(prev_max + nums[i], nums[i]);
            maxi=max(maxi, prev_max);
            
            prev_min=min(prev_min + nums[i], nums[i]);
            mini=min(mini, prev_min);
        }
        
        cout<<maxi<<" "<<mini<<endl;
        if(sum == mini)
            return maxi;
        else    
          return max(maxi, sum-mini);
    }
};