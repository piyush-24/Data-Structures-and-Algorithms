class Solution {
public:
    int maxDepth(string s)
    {
        int c=0,mx=0;
        for(auto x:s)
        {
            if(x=='(')
            {
                c++;
                mx=max(mx,c);
            }
            else if(x==')')
                c--;
            else
                continue;
        }
        return mx;
    }
};