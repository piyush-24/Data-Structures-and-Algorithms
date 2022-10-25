class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
    {
        int i=0,j=0,r=0,p=0;
        while(i<word1.size() && j<word2.size())
        {
            if(word1[i][r++]!=word2[j][p++])
                return false;
            
            if(r>=word1[i].length())
            {
                i++;
                r=0;
            }
            
            if(p>=word2[j].length())
            {
                j++;
                p=0;
            }
        }
        if(i==word1.size() && j==word2.size())
            return true;
        else
            return false;
    }
};