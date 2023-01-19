class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        unordered_map<int,int> m;
        m[0]=1;
        int head=-1, tail=0, sum=0, ans=0, n=nums.size();
       
        while(tail<n)
        {
            while(head+1<n)
            {
                head++;
                sum+=nums[head];
                int rem = (sum % k);
                
                if(rem<0)
                    rem+=k;
                    
                if(m.find(rem)!=m.end())
                    ans+=m[rem];
                
                m[rem]++;
            }
            
            if(head<tail)
            {
                tail++;
                head=tail-1;
            }
            else
            {
                tail++;
            }
        }
        return ans;
    }
};