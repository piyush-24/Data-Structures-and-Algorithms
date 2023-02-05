class Solution {
public:
    long long pickGifts(vector<int>& g, int k) {
        sort(begin(g),end(g),greater<int>());
        priority_queue<long long> pq;
        long long s=0;
        for(int i=0;i<g.size();i++)
        {
            pq.push(g[i]);
        }
       while(k--)
       {
           int j=pq.top();
           pq.pop();
           
           pq.push(sqrt(j));
       }
        
        while(pq.size()>0)
        {
            
            s+=pq.top();
            pq.pop();
        }
        return s;
    }
};