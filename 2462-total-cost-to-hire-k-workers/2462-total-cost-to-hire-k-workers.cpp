class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int can) 
    {
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        
        vector<int> visit(costs.size(),0);  
        int l ,r;      
        
        for(int i =0;i<can && i<costs.size();i++)
        {
            pq1.push(costs[i]);
            visit[i]=1;
            l = i;
        }
        l++;
        
        for(int i = costs.size()-can;i<costs.size();i++)
        {
            if(visit[i]==1)
                continue;
            
            pq2.push(costs[i]);
            visit[i]=1;
            r = i;
        }
        r= costs.size()-can-1;
        
            
        int ans = 0;
        long long sum = 0;
    
        while(ans<k)
        {      
            if((pq1.size()!=0) && (pq2.size()==0|| pq1.top()<=pq2.top()))
            { 
                int a = pq1.top();
                 pq1.pop();    
                 ans++;                                
                 sum+= a;
                
                if( l>=0 &&  l<costs.size() && visit[l]==0 )
                { 
                    pq1.push(costs[l]);
                    visit[l]=1;
                    l++;
                }
            }
            else
            {
                int a = pq2.top();
                pq2.pop();
                ans++;
                sum+= a;
                
                if(r>=0 &&  r<costs.size() && visit[r]==0 )
                {
                    pq2.push(costs[r]);
                    visit[r]=1;
                    r--;
                }  
            } 
        }
        return sum;    
    }
};