class Solution {
public:
    int addRungs(vector<int>& r, int dist) 
    {
        int c=0;
        if(r[0]>dist)
            c=(r[0]-1)/dist;
        
        for(int i=1;i<r.size();i++)
        {
            if(abs(r[i-1]-r[i])<=dist)
                continue;
            else
            {
                int y=abs(r[i]-r[i-1]-1)/dist;
                c+=(y);
            }
        }
        return c;
    }
};