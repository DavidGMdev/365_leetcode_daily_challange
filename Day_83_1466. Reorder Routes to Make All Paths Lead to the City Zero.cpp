class Solution {
public:
    int tot = 0 ; 
    void dfs( int node , vector<vector<int>>& adj , vector<vector<int>> & inv , vector<bool> &vis ){
        if( vis[node] ) return ;
        vis[node] = true;
        for( auto & child : inv[node] ) {
            dfs(child,adj,inv,vis);
        }
        for( auto & child : adj[node] ){
            if( !vis[child] ) tot++;
            dfs(child,adj,inv,vis);
            
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n) , inv(n);
        vector<bool> vis(n,false);
        for( auto & i : connections ) {
            adj[i[0]].push_back(i[1]);
            inv[i[1]].push_back(i[0]);
        }
        dfs(0,adj,inv,vis);
        return tot; 
    }
}; 
