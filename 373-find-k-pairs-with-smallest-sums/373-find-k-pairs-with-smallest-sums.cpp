class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>> , greater<pair<int, vector<int>>>> p;
        
        for(int i = 0; i < n; i++)
        p.push({nums1[i] + nums2[0], {i, 0}});
        
        vector<vector<int>> res;
        while(k-- && !p.empty())
        {
            auto temp = p.top();
            p.pop();
            int a = temp.second[0], b = temp.second[1];
            res.push_back({nums1[a], nums2[b]});
            
            if(b + 1 < m)
            {
                p.push({nums1[a] + nums2[b + 1], {a, b+1}});
            }
        }
        return res;        
    }
};