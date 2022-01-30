class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        if(n==1 || k<=0)
            return ;
        
        k=k%n;
        
        reverse(begin(nums), end(nums) );
        reverse(begin(nums), begin(nums) + k);
        reverse(begin(nums)+k, end(nums));
    }
};