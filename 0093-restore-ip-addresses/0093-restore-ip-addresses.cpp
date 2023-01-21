class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) 
    {
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                for(int k=1;k<=3;k++)
                {
                    for(int q=1;q<=3;q++)
                    {
                        if((i+j+k+q)==s.length())
                        {
                            int a,b,c,d;
                            a=stoi(s.substr(0,i));
                            b=stoi(s.substr(i,j));
                            c=stoi(s.substr(i+j,k));
                            d=stoi(s.substr(i+j+k,q));
                            if(a<=255 && b<=255 && c<=255 && d<=255)
                            { 
                                if((to_string(a)+"."+to_string(b)+"."+to_string(c)+"."+to_string(d)).length()==s.length()+3)
                                ans.push_back(to_string(a)+"."+to_string(b)+"."+to_string(c)+"."+to_string(d));
                            }
                            
                        }
                    }
                }
            }
        }
        return ans;
    }
};