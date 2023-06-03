class Solution {
public:
    int dfs(int node , vector<vector<int>>& adj , vector<int>& cost){
        int ret = cost[node];
        int Maxpath = 0;
        for( auto & child : adj[node] ){
            Maxpath = max( Maxpath , dfs(child , adj , cost) ) ;
        }
        return ret + Maxpath ; 
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for( int i = 0 ; i < n ; i++ ){
            if( manager[i] == -1 ) continue ;
            adj[manager[i]].push_back(i);
        }
        return dfs(headID, adj , informTime);
    }
};
