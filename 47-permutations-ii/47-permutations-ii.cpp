class Solution {
public:
    set<vector<int>> ans;
    void dfs(vector<int>& nums, int index)
    {
        if(nums.size()==index)
        {
            ans.insert(nums);
            return;
        }
        
       
        for(int i=index;i<nums.size();i++)
        {
           
           swap(nums[i],nums[index]);
            dfs(nums,index+1);
           swap(nums[i],nums[index]);
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<vector<int>> v;
             dfs(nums,0);
        for(auto i:ans)
            v.push_back(i);
        return v;
    }
};