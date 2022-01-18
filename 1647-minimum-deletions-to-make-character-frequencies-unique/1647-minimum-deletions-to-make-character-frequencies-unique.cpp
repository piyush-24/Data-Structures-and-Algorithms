class Solution {
public:
    int minDeletions(string s) 
    {
        unordered_map<char,int> m;
        for(auto x:s)
            m[x]++;
        
        unordered_set<int> st;
        int c=0;
        for(auto it:m)
        {
            
            while(st.find(it.second)!=st.end())
            {
                if(it.second==1)
                {
                    c++;
                    break;
                }
                c++;
                it.second--;
            }   
            st.insert(it.second);
        }
        return (c==0)?0:c;
    }
};