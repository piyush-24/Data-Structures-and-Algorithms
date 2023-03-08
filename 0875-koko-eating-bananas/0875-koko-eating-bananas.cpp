class Solution {
public:
    bool check(int mid, vector<int>& piles, int h)
    {
        long long c=0;
        for(int i=0;i<piles.size();i++)
        {
            c+=piles[i]/mid;
            if(piles[i]%mid!=0)
                c++;
        }
        return c<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int low=1,res=-1, high=*max_element(piles.begin(),piles.end());
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(mid,piles,h))
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