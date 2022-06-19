class Solution
{
    public:
        string greatestLetter(string s)
        {
            unordered_map<char, int> m;
            
            for (auto i: s) 
                m[i]++;
            
            for (char ch = 'Z'; ch >= 'A'; ch--)
            {
                if (m[ch + 32] && m[ch]) 
                {
                    string x="";
                    x+=ch;
                    return x;
                }
            }
            return "";
        }
};