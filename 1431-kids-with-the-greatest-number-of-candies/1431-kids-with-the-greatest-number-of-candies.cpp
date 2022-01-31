class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m=*max_element(candies.begin(), candies.end());
        int len=candies.size();
        vector<bool> n(len);
        for(int i=0;i<len;i++)
        {
            if(candies[i]+extraCandies>=m)
                n[i]=true;
            else
                n[i]=false;
        }
        return n;
    }
};