class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int i=0,j=0,maxi=0,sum=0;
        unordered_set<int> s;
        int n=nums.size();
        while(j<n)
        {
            if(s.find(nums[j])!=s.end())
            {
                maxi=max(maxi,sum);
                while(s.find(nums[j])!=s.end())
                {
                    sum-=nums[i];
                    s.erase(nums[i]);
                    i++;
                }
            }
            sum+=nums[j];
            maxi=max(maxi,sum);
            s.insert(nums[j]);
            j++;
        }
        return maxi;
    }
};