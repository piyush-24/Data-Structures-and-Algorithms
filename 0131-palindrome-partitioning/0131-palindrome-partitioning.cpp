class Solution {
public:
   vector<vector<string>> ans;
   bool isPal(string s, int start, int end) 
   {
        while(start<=end) 
        {
            if(s[start++]!= s[end--])
                return false;
        }
        return true;
    }
    void dfs(int index, string& s, vector<string>& ds)
    {
        if(index==s.length())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<s.length();i++)
        {
            string x=s.substr(index, i-index+1);
            if(isPal(s,index,i))
            {
            ds.push_back(x);
            dfs(i+1,s,ds);
            ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<string> ds;
        dfs(0,s,ds);
        return ans;
    }
};