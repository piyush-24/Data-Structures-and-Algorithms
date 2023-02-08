class Solution {
public:
    int totalFruit(vector<int>& f) {
        
        int head=-1, tail=0,ans=0, n=f.size(), sum=0;
        map<int,int> m;
        while(tail<n)
        {
            while(head+1<n && (m.size() +  ((m.find(f[head+1])==m.end())?1:0) <=2 )) 
            {
                head++;
                m[f[head]]++;
                sum++;
            }
            //cout<<sum<<endl;
            ans=max(ans,sum);
            
            if(head<tail)
            {
                tail++;
                head=tail-1;
            }
            else
            {
                sum--;
                m[f[tail]]--;
                if(m[f[tail]]==0)
                    m.erase(f[tail]);
                
                tail++;
            }
        }
        return ans;
    }
};