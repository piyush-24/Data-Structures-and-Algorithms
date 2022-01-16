class Solution {
public:
    int minPairSum(vector<int>& nums)
    {
        int arr[100001]={0};
        for(int i:nums)
            arr[i]++;

        int i=0,j=100000,min_max_pair_sum=0;
        
        while(i<=j)
        {
            if(arr[i] == 0)
            {
                i++;
                continue;
            }
            else if(arr[j] == 0)
            {
                j--;
                continue;
            }
            else
            {
                if(i+j > min_max_pair_sum)
                    min_max_pair_sum = i+j;
                
                arr[i]--;
                arr[j]--; 
            }
        }
        return min_max_pair_sum;
    }
};