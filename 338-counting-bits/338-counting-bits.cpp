class Solution {
public:
    vector<int> countBits(int n) 
    {
        int i=0;
        vector<int> ans;
        while(i<=n)
        {
            bitset<32> b(i);
            ans.push_back(b.count());
            i++;
        }
        return ans;
    }
};