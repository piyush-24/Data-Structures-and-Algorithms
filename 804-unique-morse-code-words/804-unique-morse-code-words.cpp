class Solution {
public:
   vector<string> v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

int uniqueMorseRepresentations(vector<string>& words) 
{
    set<string> set;

    for(int i=0; i<words.size(); i++){
        string &s = words[i];

        string transformation = "";
        for(int i=0; i<s.size(); i++){
            transformation.insert(transformation.end(),  v[s[i]-'a'].begin(), v[s[i]-'a'].end());
        }
        // cout << transformation;br;
        set.insert(transformation);
    }
    
    return set.size();
}
};