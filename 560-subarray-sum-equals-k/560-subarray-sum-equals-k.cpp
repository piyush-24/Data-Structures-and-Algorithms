class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int> m;
        m[0]=1;
        int c=0,s=0;
        for(int i=0;i<nums.size();i++)
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