class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mt) 
    {
        int n=mt.size();
        int m=mt[0].size();
        
        long long sum = 0;
        int neg = 0;
        int sm= INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                sum+=abs(mt[i][j]);
                
                if(mt[i][j]<=0)
                     neg++;
                
                sm=min(sm,abs(mt[i][j]));
                
            }
        }
        
        return (neg%2 == 0) ? sum : sum-2*sm;
    }
};