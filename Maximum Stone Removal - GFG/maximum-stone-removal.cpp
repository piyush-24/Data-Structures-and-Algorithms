//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Disjoint
{
    public:
    vector<long long> size,parent;
    Disjoint(long long n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        
        for(int i=0;i<n+1;i++)
            parent[i]=i;
    }
    
    long long findPar(long long n)
    {
        if(parent[n]==n)
            return n;
        
        return parent[n]=findPar(parent[n]);
    }
    
    void Union(long long u, long long v)
    {
        long long ulp_u=findPar(u);
        long long ulp_v=findPar(v);
        
        if(size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};



class Solution {
public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
         int max_r=0;
        int max_c=0;
        
        for(auto it:stones)
        {
            max_r=max(max_r, it[0]);
            max_c=max(max_c, it[1]);   
        }
        
        Disjoint ds(max_r+max_c+1);
        
        for(auto it:stones)
        {
            long long r=it[0];
            long long c=it[1] + max_r + 1;
            
            ds.Union(r,c);
        }
        long long c=0;
        for(int i=0;i<=max_r+max_c+1;i++)
        {
            
            if(ds.size[i]>1 && ds.parent[i]==i)
                c++;
        }
        
        return (stones.size()-c);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x; cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj,n) << "\n";
    }
}
// } Driver Code Ends