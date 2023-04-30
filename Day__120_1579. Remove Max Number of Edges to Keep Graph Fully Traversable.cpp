class Solution {
public:
    static const int N = 1e5;
    int alice[N+1],bob[N+1];
    int get( int u , int parent[] ){
        if( parent[u] == u ) return u ;
        return parent[u] = get( parent[u] , parent );
    }
    bool join( int u , int v , int parent[] ){
        u = get(u,parent);
        v = get(v,parent);
        if( u != v ) {
            parent[u] = v ; 
            return 1 ;
        }
        return 0;
    }
    static bool cmp( vector<int>&a , vector<int>&b ){
        return a[0] > b[0];
    } 
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        if ( n == 1 ) return edges.size();
        int m = edges.size();
        for ( int i = 0 ; i < n ; i++ ) alice[i] = bob[i] = i ; // init dsu 
        sort(edges.begin(),edges.end(),cmp); // make more prior to type 3 ( both )
        int cnt = 0;
        for ( int i = 0 ; i < m ; i++ ){
            int u = edges[i][1] - 1 , v = edges[i][2] - 1 ; 
            if( edges[i][0] == 3 ){
                cnt += join(u,v,alice) | join(u,v,bob);
            }
            else if ( edges[i][0] == 2 ) {
                cnt += join(u,v,bob) ;
            }
            else {
                cnt += join(u,v,alice);
            }
        }
        int p1 = get(0,alice) , p2 = get(0,bob) ;
        for( int i = 0 ; i < n ; i++ ){
            if( p1 != get(i,alice) ) return -1;
            if( p2 != get(i,bob) ) return -1;
        }
        return m-cnt ; 
    }
};
