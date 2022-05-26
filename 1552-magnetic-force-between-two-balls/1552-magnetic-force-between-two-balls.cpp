class Solution {
public:
    bool check(vector<int>& position, int m, int mid, int size)
    {
        int k=position[0],balls=1;
        for(int i=1;i<size;i++)
        {
            if(abs(k-position[i])>=mid)
            {
                balls++;
                k=position[i];
            }
        }
        if(balls<m)
            return false;
        else
            return true;
    }
    int maxDistance(vector<int>& position, int m)
    {
        int res=-1,n=position.size();
        sort(position.begin(),position.end());
        int start=1,end=position[n-1]-position[0];
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(check(position,m,mid,n))
            {
                res=mid;
                start=mid+1;
            }
            else
                end=mid-1;
        }
        return res;
    }
};