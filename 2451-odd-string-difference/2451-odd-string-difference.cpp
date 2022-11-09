class Solution {
public:
    string oddString(vector<string>& words) {
        unordered_map<string, int> mp;
        unordered_map<string, string> amp;
        for(auto w: words)
        { 
            string s = ""; 
            for(int j = 0; j < w.size()-1; ++j)
            {   
                //concatenate each nuber with a "_" in between
                int t = w[j+1] - w[j];
                s += to_string(t) + "_";
            }
            mp[s]++;   //add it to map and increament the value
            amp[s] = w;   //preserve the original string reference
        }
        for(auto m: mp)
        {  
            //scan for string with count equal to 1 ( unique string )
            
            if(m.second == 1) return amp[m.first];   //return original string when found
        }
        return "";
    }
};