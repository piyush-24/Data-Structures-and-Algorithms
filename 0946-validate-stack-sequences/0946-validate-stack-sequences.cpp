class Solution {
public:
    bool validateStackSequences(vector<int>& ps, vector<int>& pp)
    {
        int n=ps.size(),m=pp.size(),i=0,j=0;
        stack<int> st;
        while(j<n || i<m)
        {
            if(st.empty())
                st.push(ps[j++]);
            else
            {
                while(!st.empty() && pp[i]==st.top())
                {
                    st.pop();
                    i++;
                }
                if(j<n)
                st.push(ps[j++]);
                else
                    break;
            }
        }
       
        if(i==m)
            return true;
        else
            return false;
    }
};