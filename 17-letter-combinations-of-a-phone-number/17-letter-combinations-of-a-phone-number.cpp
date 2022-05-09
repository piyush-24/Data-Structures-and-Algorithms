class Solution {
public:
    string ar[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    void rec(int i, string& digits, string& ds)
    {
        if(i==digits.length())
        {
            ans.push_back(ds);
            return;
        }
        for(char s: ar[digits[i]-'0'])
          {
                ds.push_back(s);
                rec(i+1,digits,ds);
                ds.pop_back();   
          }
    }
    vector<string> letterCombinations(string digits) 
    {
        string ds;
        if(digits.length()==0)
            return ans;
        rec(0,digits,ds);
        return ans;
    }
};