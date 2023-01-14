class DisjointSet{
public:
    vector<int> size, parent, rank;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void UnionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v){
            return;
        }
        if(rank[ulp_u]<rank[ulp_v]){
            parent[u] = ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[v] = ulp_u;
        }
        else{
            parent[v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void UnionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v){
            return;
        }
        if(ulp_u>ulp_v){
            parent[ulp_u] = parent[ulp_v];
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = parent[ulp_u];
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int V = s1.length();
        DisjointSet ds(26);
        for(int i=0; i<V; i++){
            int u = s1[i]-'a';
            int v = s2[i]-'a';
            ds.UnionBySize(u,v);
        }
        string ans;
        int n = baseStr.length();
        for(int i=0; i<n; i++){
            ans+=(char)(ds.findUPar(baseStr[i]-'a') + 'a');
        }
        return ans;
    }
};