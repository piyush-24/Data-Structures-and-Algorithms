class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> v1,v2;
        
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
                v1.push_back(nums[i]);
            else
                v2.push_back(nums[i]);
        }
        
        sort(begin(v1),end(v1));
        sort(begin(v2),end(v2),greater<int>());
        
        int j=0;
        for(int i=0;i<n;i+=2)
             nums[i]=v1[j++];
        
        j=0;
        for(int i=1;i<n;i+=2)
             nums[i]=v2[j++];
         
        return nums;
    }
};