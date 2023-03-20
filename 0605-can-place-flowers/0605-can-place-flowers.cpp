class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n)
    {
        int len=fb.size();
        if(n==0)
            return true;
        if(len==1 && n==1 && fb[0]==0)
        {
                return true;
        }
           
        if(fb.size()>=2 && fb[0]==0 && fb[1]==0)
        {
            fb[0]=1;
            n--;
        }
        for(int i=1;i<fb.size()-1;i++)
        {
            if(fb[i]==0 && fb[i-1]==0 && fb[i+1]==0)
            {
                fb[i]=1;
                n--; 
            }   
        }
        if(fb.size()>=2 && fb[len-1]==0 && fb[len-2]==0)
        {
            fb[len-1]=1;
            n--;
        }
        
        return n<=0;
    }
};