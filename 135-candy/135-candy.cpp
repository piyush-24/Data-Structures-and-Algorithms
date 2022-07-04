class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int len=ratings.size();
        int x=0;
        vector<int> ls(len,1);
        vector<int> rs(len,1);
       
        for(int i=1;i<len;i++)
        {
            if(ratings[i-1]<ratings[i])
                ls[i]=ls[i-1]+1;
        }
        for(int i=len-1;i>=1;i--)
        {
            if(ratings[i]<ratings[i-1])
                rs[i-1]=rs[i]+1;
        }
         for(int i=0;i<len;i++)
            x+=max(ls[i],rs[i]);
        return x;
    }
};