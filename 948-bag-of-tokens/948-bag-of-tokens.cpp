class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int power)
    {
        sort(t.begin(),t.end());
        int n=t.size();
        int i=0,j=n-1;
        int sc=0;
      
        while(i<=j)
        {
            if(power>=t[i])
            {
                power-=t[i];
                i++;
                sc+=1;
            }
            else if(sc>0 && i<j)
            {
                power+=t[j];
                sc-=1;
                j--;
            }
            else break;
            
        }
        return sc;
    }
};