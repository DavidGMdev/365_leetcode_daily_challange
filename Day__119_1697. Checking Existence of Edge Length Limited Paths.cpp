class Solution {
public:
    static const int N = 1e5;
    int parent[N+1];
    int get( int u ){
        if( parent[u] == u ) return u ;
        return parent[u] = get( parent[u] );
    }
    void join( int u , int v ){
        u = get(u);
        v = get(v);
        if( u != v ) parent[u] = v ; 
    }
    static bool custom(vector<int> & a , vector<int> & b){
        return(a[2] < b[2]) ;
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        for( int i = 0 ; i < n;  i++ ) parent[i] = i ; // init dsu
        sort(edgeList.begin(),edgeList.end(),custom);
        for ( int i = 0 ; i < queries.size() ; i++ ){
            queries[i].push_back(i); // hold index for answer saving 
        }
        sort(queries.begin(),queries.end(),custom);
        int m = edgeList.size() , q = queries.size();
        int i = 0 , j = 0 ; 
        vector<bool> ans(q,false);
        while( i < q ){
            while ( j < m && edgeList[j][2] < queries[i][2] ) {
                join( edgeList[j][0] , edgeList[j][1] ) ;
                j++;
            }
            ans[queries[i][3]] = get(queries[i][0]) == get(queries[i][1]);
            i++;
        }
        return ans;
    }
};
