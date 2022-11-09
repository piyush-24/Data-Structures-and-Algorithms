class Solution 
{
public:
    string oddString(vector<string>& words) 
    {
        map<vector<int>,vector<string>> eq;
        
        for (string w : words)
        {
            vector<int> diff;
            for (int i = 1; i < w.size(); ++i)
                diff.push_back(w[i]-w[i-1]);
            eq[diff].push_back(w);
        }
        
        for (auto&[_, ws] : eq)
            if (ws.size() == 1)
                return ws[0];
        
        return words[0]; // unreachable
    }
};