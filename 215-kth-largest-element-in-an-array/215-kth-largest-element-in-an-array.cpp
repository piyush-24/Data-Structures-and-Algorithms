class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int>maxheap(nums.begin(),nums.end());
        
        while(k--!=1) 
            maxheap.pop();
        
        return maxheap.top();
    }
};