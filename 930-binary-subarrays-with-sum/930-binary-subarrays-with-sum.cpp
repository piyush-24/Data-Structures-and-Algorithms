class Solution {
public:
     
    int numSubarraysWithSum(vector<int>& nums, int k)
    {
       unordered_map<int,int> m;
        m[0]=1;
        int len=nums.size();
        int s=0,c=0;
        for(int i=0;i<len;i++)
        {
            s+=nums[i];
            if(m[s-k]>0)
            {
                c+=m[s-k];
            } 
             m[s]++;
        }
        return c;
    }
};