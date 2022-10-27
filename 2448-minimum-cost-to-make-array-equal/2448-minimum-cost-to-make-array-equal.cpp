class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        //Concept of weighted median
        
        long long m, sum = 0, ans = 0;
        for(int i=0;i<cost.size();i++) 
            sum+=(long long)(cost[i]);
        
        //Storing in form of pairs and sorting it so as to find the median 
        
        vector<pair<int,int>> p;
        for(int i=0;i<nums.size();i++) 
            p.push_back({nums[i],cost[i]});
        
        sort(p.begin(),p.end());
        
        // for(auto i:p) 
        //     cout<<i.first<<" "<<i.second<<endl;
        //Finding out the median value 
        //Bcoz across median value, the cost can be minimised
        long long curr = 0, i = 0;
        while(curr < (sum+1)/2 && i<nums.size())
        {
            curr += p[i].second;
            m = p[i].first; i++;
        }
        
        for(int i=0;i<nums.size();i++) 
        {
            ans += abs((long long)(nums[i]-m))*((long long)cost[i]);
        }
        
        return ans;
    }
};