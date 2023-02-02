class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) 
    {
         int map[26];
        for(int i=0;i<26;i++)
            map[order[i]-'a']=i;
        
        for(auto& s:words)
            for(auto& ch:s)
                ch=map[ch-'a'];
        
        return is_sorted(words.begin(),words.end());
    }
};