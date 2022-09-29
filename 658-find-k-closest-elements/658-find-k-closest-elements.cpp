class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        int n = size(arr), R = lower_bound(begin(arr), end(arr), x) - begin(arr), L = R - 1;

        while(k--) 
        {
             if(R >= n || L >= 0 && x - arr[L] <= arr[R] - x) 
                L--;                                              
            else
                R++;  
        }
                                                       
        vector<int> ans;
        for(int i=L+1;i<R;i++)
            ans.push_back(arr[i]);
        return ans;
    }
};