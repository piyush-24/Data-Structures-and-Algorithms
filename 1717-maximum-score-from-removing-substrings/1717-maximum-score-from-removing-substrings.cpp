class Solution {
public:
    int f(string& s, char a, char b)
    {
        stack<char> st;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
                st.push(s[i]);
            else if(st.top()==a && s[i]==b)
            {
                st.pop();
                ans++;
            }
            else
                st.push(s[i]);
            
        }
        string str;
        while(!st.empty())
        {
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        s=str;
        return ans;
    }
    int maximumGain(string s, int x, int y) 
    {
        int xx=0,yy=0;
       if(x>y)
       {
           xx=f(s,'a','b');
           yy=f(s,'b','a');
       }
        else
        {
             yy=f(s,'b','a');
             xx=f(s,'a','b');
        }
        return x*xx+y*yy;
    }
};