// ##########################################
// solution 1.1 : More optimized solution 
// ##########################################

class Solution {
public:
    int get( int u , vector<int>& parent ){
        if( parent[u] == u ) return u ;
        return parent[u] = get( parent[u] , parent );
    }
    void join( int u , int v , vector<int>& parent ){
        u = get( u , parent ) , v = get( v , parent );
        if( u != v ) parent[v] = u ; 
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if ( connections.size() < n - 1 ) return -1;
        vector<int>parent(n);
        for( int i = 0 ; i < n ; i++ ) parent[i] = i ; // init  
        int links = n - 1 ;
        for( auto & i : connections ) {
            if ( get(i[0],parent) != get(i[1],parent) ) {
                join(i[0],i[1],parent);
                links--;
            }
        }
        return links; // rest of links is the qunatity needed 
    }
};

// ####################################################
// solution 1 : using DSU and unique components check
// ####################################################

class Solution {
public:
    int get( int u , vector<int>& parent ){
        if( parent[u] == u ) return u ;
        return parent[u] = get( parent[u] , parent );
    }
    void join( int u , int v , vector<int>& parent ){
        u = get( u , parent ) , v = get( v , parent );
        if( u != v ) parent[v] = u ; 
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>parent(n);
        for( int i = 0 ; i < n ; i++ ) parent[i] = i ; // init  
      
        int extra = 0 ;
        for( auto & i : connections ){
            if ( get(i[0],parent) != get(i[1],parent) ) join(i[0],i[1],parent);
            else extra++;
        }
      
        set<int> unique;
        for( int i = 0 ; i < n ; i++ ) {
            unique.insert(get((i),parent)) ;
        }
      
        int components = unique.size() ; 
        return ( ( components-1 <= extra ) ? components - 1 : -1 ) ; 

    }
};
