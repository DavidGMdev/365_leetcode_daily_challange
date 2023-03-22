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
            if( get(road[0]) == get(0) || get(road[1]) == get(0) ) {
                ans = min(ans, road[2]);
            }
        }
        return ans;
    }
};
