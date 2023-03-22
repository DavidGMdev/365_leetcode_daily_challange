class Solution {
public:
    static const int N = 1e5 ;
    int parent[N+1];
    int get( int node ){
        if ( parent[node] == node ) return node;
        return parent[node] = get(parent[node]);
    }
    void join( int u , int v ){
        u = get(u);
        v = get(v);
        if ( u != v ) parent[v] = u ;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        // idea : dsu ? in same component => can be minimize with 
        for( int i = 0 ; i < n ; i++ ) parent[i] = i ; // init 
        for(auto & road : roads) {
            join(--road[0],--road[1]);
        }
        int ans = INT_MAX ;
        for(auto & road : roads){
            if( get(road[0]) == get(0) ) {
                ans = min(ans, road[2]);
            }
        }
        return ans;
    }
};
// ###############################
// another solution using DFS
// ###############################

class Solution {
public:

    void dfs( int curr , vector<vector<pair<int,int>>> & edg , vector<bool>&vis , int & ans ){
        if( vis[curr] ) return ;
        vis[curr] = true ;
        for(auto & edge : edg[curr]){
            ans = min(edge.first , ans) ; 
            dfs(edge.second,edg,vis,ans) ;
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> edg(n); // w, node => edges
        vector<bool>vis(n,false);

        for( auto & road : roads ){
            road[0]-- , road[1]--;
            edg[ road[0] ].push_back( { road[2] , road[1] } ) ;
            edg[ road[1] ].push_back( { road[2] , road[0] } ) ;
        }
        int ans = INT_MAX ;
        // all visited edges are strongly coneected component => can minimize 
        dfs(0,edg,vis,ans); 
        return ans ;
    }
};
