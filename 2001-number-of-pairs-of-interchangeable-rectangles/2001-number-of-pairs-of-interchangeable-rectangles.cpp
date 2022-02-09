class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& r)
    {
        unordered_map<long double,int> m;
        long long c=0;
        for(int i=0;i<r.size();i++)
        {
           long double x=(double)r[i][1]/(double)r[i][0];
            if(m.find(x)!=m.end())
                c+=(m[x]);
            m[x]++;
        }
        return c;
    }
};