class Solution {
public:
    int maxProfit(vector<int>& p) 
    {
        int buy=p[0],sell=0;
        for(int i=1;i<p.size();i++)
        {
            buy=min(buy,p[i]);
            sell=max(sell,p[i]-buy);
        }
        return sell;
    }
};