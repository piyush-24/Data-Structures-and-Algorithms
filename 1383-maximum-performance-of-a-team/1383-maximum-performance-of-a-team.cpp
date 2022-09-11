class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k)
    {
        vector<pair<int, int>> ess(n);
        
        for (int i = 0; i < n; ++i)
            ess[i] = {efficiency[i], speed[i]};
        
        sort(rbegin(ess), rend(ess));
        long sumS = 0, res = 0;
        
        priority_queue <int, vector<int>, greater<int>> pq; //min heap
        
        for(auto& [e, s]: ess)      // s[] = {6, 5, 2, 15, 3, 8}
        {                           // e[] = {9, 7 ,5, 4, ,3 ,2}
            pq.emplace(s);
            sumS += s;
            if (pq.size() > k) {
                sumS -= pq.top();
                pq.pop();
            }
            res = max(res, sumS * e);
        }
        return res % (int)(1e9+7);
    }
};