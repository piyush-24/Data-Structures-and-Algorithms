class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int i=0,j=0,c=0;
        int n=nums.size();
        int p=1;
        while(j<n)
        {
            p*=nums[j]; 
            while(p>=k  && i<=j)
            {
                p/=nums[i];
                i++;
            }
            c+=(j-i+1);
            j++;
        }
        return c;
    }
};