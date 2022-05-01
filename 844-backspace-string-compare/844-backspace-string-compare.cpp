class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        stack<char> q1,q2;
        for(auto x:s)
        {
            if(!q1.empty() && x=='#')
                q1.pop();
            else if(x!='#')
                q1.push(x);
        }
        for(auto x:t)
        {
            if(!q2.empty() && x=='#')
                q2.pop();
            else if(x!='#')
                q2.push(x);
        }
        return (q1==q2);
    }
};