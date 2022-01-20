class Solution {
public:
    bool check(char x)
    {
        return (x=='a'||x=='i'||x=='o'||x=='u'||x=='e');
    }
    int maxVowels(string s, int k) 
    {
        int i=0,j=0,n=s.size(),c=0,maxi=0;
        while(j<n)
        {
                if(check(s[j]))
                    c++;
            if((j-i+1)==k)
            {
                maxi=max(maxi,c);
                if(check(s[i]))
                    c--;
                i++;
            }
           j++; 
        }
        return maxi;
    }
};