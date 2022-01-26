class Solution {
public:
   
    int minFallingPathSum(vector<vector<int>>& triangle)
    {
        int n=triangle.size();
        
        vector<int> front(n,0), curr(n,0);
        for(int i=0;i<n;i++)
            front[i]=triangle[n-1][i];
        
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                 int rdg=INT_MAX,ldg=INT_MAX,d=INT_MAX;
                 d=  triangle[i][j]+front[j];
                
                if(j+1<n)
                 rdg= triangle[i][j]+front[j+1];
                
                if(j-1>=0)
                 ldg= triangle[i][j]+front[j-1];

                curr[j]=min({d,rdg,ldg});
            }
          front=curr;  
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
            ans=min(ans,front[i]);
        return ans ;
    }
};