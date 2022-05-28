class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A)
    {
        int sum = 0;
        // sum up vector
        for (auto a : A)
            sum += a;
        // if the total sum doesn't divide into three, return false
        if (sum % 3 != 0)
            return false;
        int each = sum/3, temp = 0, found = 0;
        // count parts with right sum
        for (int i=0; i<A.size(); i++) 
        {
            temp += A[i];
            if (temp == each) 
            {
                temp = 0;
                found++;
            }
        }
        return found>=3? true : false;
    }
};