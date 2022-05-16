class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& s)
    {
        sort(begin(s),end(s));
        int maxi=0;
        maxi=max(maxi,s[0]-bottom);
        maxi=max(maxi,top-s[s.size()-1]);
        for(int i=1;i<s.size();i++)
        {
            maxi=max(maxi,s[i]-s[i-1]-1);
        }
        return maxi;
    }
};