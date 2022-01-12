class Solution {
public:
    int totalFruit(vector<int>& f) 
    {
        int i=0,j=0,n=f.size(),maxi=0;
        unordered_map<int,int> m;
        while(j<n)
        {
            m[f[j]]++;
            if(m.size()>2)
            {
                while(m.size()>2)
                {
                    m[f[i]]--;
                    if(m[f[i]]==0)
                        m.erase(f[i]);
                    i++;
                }
                
            }
            if(m.size()<=2)
                maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};