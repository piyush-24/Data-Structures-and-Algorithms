class Solution {
public:
    int maxPoints(vector<vector<int>>& p) 
    {
        int maxi=2;
        int n=p.size();
        if(n<=2)
            return n;
        for(int i=0;i<n;i++)
        {
            int x1=p[i][0],y1=p[i][1];
            for(int j=i+1;j<n-1;j++)
            {
                int x2=p[j][0],y2=p[j][1];
                int total=2;
                for(int k=0;k<n;k++)
                {
                    int x3=p[k][0],y3=p[k][1];
                    
                    if(((y2-y1)*(x3-x2))==((y3-y2)*(x2-x1)) && k!=j && k!=i)
                        total++;
                }
               maxi=max(maxi,total); 
            }
        }
        return maxi;
    }
};