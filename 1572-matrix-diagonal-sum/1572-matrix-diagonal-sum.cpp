class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat)
    {
         int res = 0;
        int n = mat.size();
        for (int i=0; i<n; i++) 
        {
            res += mat[i][i]; // Primary diagonals are row = column! 
            res += mat[n-1-i][i]; // Secondary diagonals are row + column = n-1!
        }
        return n % 2 == 0 ? res : res - mat[n/2][n/2];
    }
};