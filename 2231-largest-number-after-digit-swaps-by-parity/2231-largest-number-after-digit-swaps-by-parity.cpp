class Solution {
public:
    int largestInteger(int num) 
    {
        string s=to_string(num);
        int n=s.size();
        string s1,s2;
        
        for(int i=0;i<n;i++)
        {
            if((s[i]-'0')%2==0)
                s1.push_back(s[i]);
            else
                s2.push_back(s[i]);
        }
        
        sort(begin(s1),end(s1));
        reverse(begin(s1),end(s1));
        
        sort(begin(s2),end(s2));
        reverse(begin(s2),end(s2));
        
        int j=0,k=0;
        for(int i=0;i<n;i++)
        {
            if((s[i]-'0')%2==0)
                s[i]=s1[j++];
            else
                s[i]=s2[k++];
        }
           
        
        return stoi(s);
    }
};