class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> vec;
        string str="";
        s+=' ';
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                vec.push_back(str);
                str="";
            }
            else
                str+=s[i];
        }
        
        if(vec.size()!=pattern.size())
            return false;
        
        map<char,int> mpp;
        map<string,int> mps;
        for(int i=0;i<vec.size();i++)
        {
            if(mps[vec[i]]!=mpp[pattern[i]])
                return false;
            mps[vec[i]]=i+1;
            mpp[pattern[i]]=i+1;
        }
    
    return true;
    }
};