class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int index, int target, vector<int>& ds, vector<int> c)
    {
            if(target==0)
           {
                ans.push_back(ds);
                return;
           }
           if(index==c.size())
                return;
        
        if(target>=c[index])
        {
            ds.push_back(c[index]);
            dfs(index, target-c[index],ds,c);
            ds.pop_back();
        }
        dfs(index+1,target,ds,c);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) 
    {
        sort(c.begin(),c.end());
        vector<int> ds;
        dfs(0,target,ds,c);
        return ans;
    }
};