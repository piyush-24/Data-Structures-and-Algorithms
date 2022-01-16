class Solution {
public:
    int atmost(vector<int>& nums, int k)
    {
        int j=0,i=0,n=nums.size(), c=0;
        unordered_map<int,int> m;
        while(j<n)
        {
           m[nums[j]]++;
           while(m.size()>k)
           {
               m[nums[i]]--;
               if(m[nums[i]]==0)
                   m.erase(nums[i]);
                   
                   i++;
           }
            c+=j-i+1;
            j++;
        }
        return c;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return(atmost(nums,k)-atmost(nums,k-1));
    }
};