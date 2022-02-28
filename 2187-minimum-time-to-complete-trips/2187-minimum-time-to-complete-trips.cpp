class Solution {
public:
    long long bb(vector<int>& t, int trip, long long mid)
    {
        long long c=0;
        for(int i=0;i<t.size();i++)
            c+=(mid/t[i]);
        
        return (c>=trip);
    }
    long long minimumTime(vector<int>& t, int trip) 
    {
        long long low,high,res=0;
        low=0,high=100000000000000;
        while(low<=high)
        {
            long long mid=(low+high)>>1;
            if(bb(t,trip,mid))
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