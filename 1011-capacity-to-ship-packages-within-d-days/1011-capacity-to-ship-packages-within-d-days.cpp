class Solution {
public:
    bool check(int mid, vector<int>& weights, int days)
    {
        int c=1,s=0;
        for(int i=0;i<weights.size();i++)
        {
            if(s+weights[i]>mid)
            {
                c++;
                s=weights[i];
            }
            else
                s+=weights[i];
        }
        return c<=days;
    }
    int shipWithinDays(vector<int>& weights, int days)
    {
        int res=-1,low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(mid,weights,days))
            {
                res=mid;
                high=mid-1;
            }
            else
                low=mid+1;       
        }
        return res;
    }
};