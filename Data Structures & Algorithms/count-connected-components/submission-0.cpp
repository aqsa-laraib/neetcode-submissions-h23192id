class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int> &vis){
        vis[node]=1;
        for(auto nei:adj[node]){
            if(!vis[nei]){
                dfs(nei,adj,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                c++;
                dfs(i,adj,vis);
            }
        }
        return c;
    }
};
