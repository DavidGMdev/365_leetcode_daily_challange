// ################################
// Solution 2 : optimization
// ################################

class Solution {
public:
    // more optmized version 
    // remove useless visited , since roads are premised to be tree structure 
    // remove inv and use pair insted in adj 
    // if 1 then it's actually happens to be forward , we must invert it 
    
    void dfs( int curr , int parent , vector<vector<pair<int,int>>> & adj , int &ans ){
        for( auto & edge : adj[curr] ){
            int child = edge.first  , state = edge.second ; 
            if( child == parent ) continue ; 
            ans += state ;
            dfs(child,curr,adj,ans);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n) ;
        for( auto & i : connections ) {
            adj[i[0]].push_back({i[1],1});
            adj[i[1]].push_back({i[0],0});
        }
        int ans = 0 ; 
        dfs(0,-1,adj,ans);
        return ans; 
    }
};

// ################################
// Solution 1 : main idea
// ################################

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
