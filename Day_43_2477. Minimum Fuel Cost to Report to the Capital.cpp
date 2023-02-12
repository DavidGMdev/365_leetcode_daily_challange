class Solution {
public:
    long long ans = 0 ; // liters
    int dfs( int node , int & seats , vector<int> adj[] , vector<bool> & vis ){
        if( vis[node] ) return 0;
        vis[node] = true ;
        int total = 1;
        for( auto & i : adj[node] ) {
            total += dfs(i,seats,adj,vis);
        }
        if(node) ans += ((total*1ll+(seats-1)*1ll)/seats*1ll);
        return total;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int m = roads.size() ; // n-1 
        int n = m+1 ;
        vector<int> adj[n] ;
        vector<bool> vis(n,false);
        for(auto &i : roads){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(0,seats,adj,vis);
        return ans ;
    }
};
