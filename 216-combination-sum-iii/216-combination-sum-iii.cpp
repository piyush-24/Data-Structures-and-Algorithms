class Solution {
public:
    vector<vector<int>> ans;
    void rec(int index,vector<int> ds, int k, int n)
    {
        if(ds.size()>k || n<0)
            return;
        if(ds.size()==k && n==0)
            ans.push_back(ds);
        for(int i=index;i<=9;i++)
        {
            ds.push_back(i);
            rec(i+1,ds,k,n-i);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<int> ds;
        rec(1,ds,k,n);
        return ans;
        
    }
};