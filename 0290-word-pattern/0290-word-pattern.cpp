class Solution {
public:
    
bool wordPattern(string pattern, string s) 
{
    unordered_map < char, string > mp;
    unordered_map < string, bool > m;

    vector < string > a;
    istringstream ss(s);

    string word;
    while (ss >> word)
    {
      a.push_back(word);
    }

    if (pattern.length() != a.size())
      return false;

    for (int i = 0; i < a.size(); i++) 
    {
      if (mp.find(pattern[i]) != mp.end()) 
      {

        if (mp[pattern[i]] != a[i])
          return false;

      }
        else if (m[a[i]])
        return false;
      else 
      {
        mp[pattern[i]] = a[i];
        m[a[i]] = true;
      }
    }

    return true;
  }
};