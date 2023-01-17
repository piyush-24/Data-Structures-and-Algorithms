class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
        int f = 0, cnt = 0;
        for (auto c : s) 
        {
            if (c == '1')
                cnt++;
            else 
                f++;
            
            f = min(f, cnt);
        }
        return f;
    }
};