class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
         int mid, n = matrix.size();
        int m = matrix[0].size();
        int start=0,end=m*n-1;
        while(start<=end)
        {
            mid=(start+end)/2;
            if(matrix[mid/m][mid%m]==target)
                 return true;
            else if(matrix[mid/m][mid%m]<target)
                start=mid+1;
            else
                end=mid-1;
        }
       return false ;
    }
};