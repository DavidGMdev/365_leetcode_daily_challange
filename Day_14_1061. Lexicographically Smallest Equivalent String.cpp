// ##############################
// solution one [ direct DSU ]
// ##############################

class Solution {
public:
    int parent[26]; 
    int get(int x) {
        if ( parent[x] == x ) return x;
        return parent[x] = get( parent[x] ) ;  
    }
    void join(int a , int b) {
        a = get(a);
        b = get(b);
        if ( a == b ) return ; 
        // keep parent of set is min lexographiocally 
        if ( a < b ) parent[b] = a ;  
        else parent[a] = b ; 
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for ( int i = 0 ; i < 26 ; i++ ) parent[i] = i ; // init 
        int n = s1.size() , m =  baseStr.size() ; 
        for ( int i = 0 ; i < n ; i++ ) {
            join( s1[i] - 'a' , s2[i] - 'a' ) ; 
        }      
        for ( int i = 0 ; i < m ; i++ ) {
            baseStr[i] = get( baseStr[i] - 'a' ) + 'a' ;
        }
        return baseStr ;
    }
};

// ####################################################################################
// solution two [ in-direct idea of DSU , make use of having just 26 unique element ]
// ####################################################################################

class Solution {
public:
    int parent[26]; 
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for ( int i = 0 ; i < 26 ; i++ ) parent[i] = i ; // init 
        int n = s1.size() , m =  baseStr.size() ; 
        for ( int i = 0 ; i < n ; i++ ) {
            int mn = min ( parent[ s1[i] - 'a' ] , parent[ s2[i] - 'a' ] ); 
            int mx = max ( parent[ s1[i] - 'a' ] , parent[ s2[i] - 'a' ] );
            for ( int j = 0 ; j < 26 ; j++ ) {
                if ( parent[j] == mx ) parent[j] = mn ; 
            }
        }      
        for ( int i = 0 ; i < m ; i++ ) {
            baseStr[i] = parent[ baseStr[i] - 'a' ] + 'a' ;
        }
        return baseStr ;
    }
};


