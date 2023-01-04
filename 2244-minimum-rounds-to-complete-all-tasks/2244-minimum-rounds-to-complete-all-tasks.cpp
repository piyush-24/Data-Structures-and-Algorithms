class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> m;
        for(auto it:tasks)
             m[it]++;
        
        for(auto it:m)
        {
            if(it.second==1)
                return -1;
        }
        int ans=0;
         for(auto it:m)
        {
             cout<<it.first<<" "<<it.second<<endl;
             
            if((it.second%3)==0)
                ans+=(it.second/3);
            else if((it.second)==2)
               ans+=1;
            else
            {
                ans++;
                int x=it.second;
                while(x>=3)
                {
                    ans++;
                    x-=3;
                }
                
            }
             
             cout<<ans<<endl;
        }
        
       return ans; 
    }
};