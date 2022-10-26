class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int> m;
        m[0]=-1;
        int s=0,r=0,c=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            r=s%k;
            
            if(m.find(r)!=m.end())
            {
                if(abs(i-m[r])>1)
                    return true;
            }
            
            if(m.find(r)==m.end())
               m[r]=i;
        }
        return false;
    }
};