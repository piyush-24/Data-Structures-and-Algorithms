class Solution {
public:
    vector<vector<int>> ans;
    void rec(int index, int n, int k, vector<int>& ds)
    {
        if(ds.size()==k)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<=n;i++)
        {
            ds.push_back(i);
            rec(i+1,n,k,ds);
            ds.pop_back();   
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> ds;
        rec(1,n,k,ds);
        return ans;
    }
};