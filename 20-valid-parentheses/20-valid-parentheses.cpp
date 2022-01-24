class Solution {
public:
    bool isValid(string s)
    {
        unordered_map<char,char> m;
        stack<int> st;
        m[')']='(';
        m['}']='{';
        m[']']='[';
        
        if(s.size() &1)
            return false;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            else
            {
                char x=s[i];
                if(!st.empty() && st.top()==m[x])
                    st.pop();
                else
                    return false;
            }
        }
        if(st.size()>0)
            return false;
        return true;
    }
};