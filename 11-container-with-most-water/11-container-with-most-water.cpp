class Solution {
public:
    int maxArea(vector<int>& h)
    {
        long long int i=0,j=h.size()-1,maxi=0;
        while(i<j && i<h.size() && j>0)
        {
            maxi=max(maxi,abs(j-i)*(min(h[i],h[j])));
                if(h[i]<h[j])
                   i++;
                else
                   j--;
        }
        return maxi;
    }
};