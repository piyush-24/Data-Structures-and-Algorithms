class Solution {
public:
    string removeOccurrences(string s, string part)
    {
         int i = 0, j = 0, k= part.length();
        
        while(j<s.length())
        {
            if(j-i+1<k) // less than window size
                j++;
            else if(j-i+1 == k)                         // equal to window size
            { 
                if(s.substr(i,k) == part)
                {                                       //matched
                    s.erase(i,k);                       //remove
                    i = 0; j = 0;                       //reset pointers
                }
                else
                {
                    i++;
                    j++; //otherwise incremenet pointers
                }
            }
        }
        return s;
    }
};