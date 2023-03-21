class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long c=0,n=nums.size(),res=0;
        for(int i=0;i<=n;i++)
        {
            if(i<n  && nums[i]==0)
                c++;
            else
            {
                res+=((c*(c+1))/2);
                //c++;
                c=0;
            }
        }
        return res;
        
    }
};