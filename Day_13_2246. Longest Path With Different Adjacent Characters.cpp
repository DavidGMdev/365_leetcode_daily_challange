// ######################################################
// main idea
// ######################################################


// ######################################################
// Solution 4 : most optimized  
// ######################################################



// ######################################################
// Solution 3 : less code , more optimized  
// ######################################################

class Solution {
public:
    static const int N = 1e5 ; 
    vector<int> adj[N+5] ;
    bool vis[N+5] = {0};
    int path[N+5] = {0};
    int ans = 1 ;

    bool canJoin(int a , int b , string & x){
        return ( x[a] != x[b] );
    }

    void dfs( int node , string & x ) {
        if ( vis[node] ) return ;
        vis[node] = true ; 
        
        int l = -1 , r = -1 ;
        int maxLinePath = 0 , maxJointPath = 0 ; 
      
        for( auto & child : adj[node] ){

            // visit all children 
            dfs(child,x);

            // if cannot join this child to the parent just skip the proces 
            if ( !canJoin(node,child,x) ) continue ;

            // maximize the path to take , which child have the longest path 
            maxLinePath = max(maxLinePath,path[child]);

            // ge the max 2 elements from child paths
            // that can be bend using the current node as joint for the bended path  
            if ( ( l == -1 || path[child] > path[l] ) && (r == -1 || path[l] > path[r]) ) r = l ; 
            if ( l == -1 || path[child] > path[l]) l = child ;
            else if ( r == -1 || path[child] > path[r] ) r = child ;

        }

        // update the main line path 
        // maximize the answer 
        path[node] = maxLinePath + 1 ;
        ans = max ( ans , path[node] ) ;


        // if no sufficent children [ max 2 children ] , u cannot for a joint based path
        // so just skip it 
        if ( l == -1 || r == -1 ) return ; 

        // update the main joint path 
        // maximize the answer 
        maxJointPath = path[l] + path[r] ; 
        ans = max ( ans , maxJointPath + 1 ) ;

        return ; 
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n = s.size() ;
        for( int i = 1 ; i < parent.size() ; i++ ) {
            int j = parent[i]; 
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        dfs(0,s);
        return ans ; 
    }
};



// ######################################################
// Solution 2 : more optimized  
// ######################################################

class Solution {
public:
    static const int N = 1e5 ; 
    vector<int> adj[N+5] ;
    bool vis[N+5] = {0};
    int path[N+5] = {0};
    int ans = 1 ;

    bool canJoin(int a , int b , string & x){
        return ( x[a] != x[b] );
    }
    void joint( int parent , string & x ) {
        int jointPath = 0;
        int idx = -1 , mx = -1 , idx2 = -1 , mx2 = -1 ;
        for( auto &child : adj[parent] ) {
            if ( !canJoin(parent,child,x) ) continue;
            if ( path[child] > mx ) {
                mx = path[child] ; 
                idx = child ;
            }
        }
        for( auto &child : adj[parent] ) {
            if ( !canJoin(parent,child,x) ) continue;
            if ( path[child] > mx2 && child != idx ) {
                mx2 = path[child] ; 
                idx2 = child ;
            }
        }
        if ( idx == -1 || idx2 == -1 ) return ;
        jointPath = mx + mx2 + 1 ;
        ans = max ( ans , jointPath ) ; 
         
    }

    void line( int parent , string & x ){ 
        path[parent] = max( path[parent] , 1 ); 
        for( auto &child : adj[parent] ) {
            if ( !canJoin(parent,child,x) ) continue ;
            path[parent] = max( path[parent] , path[child] + 1 );
        }
        ans = max( ans , path[parent] ) ; 
        return ; 
    }

    void dfs( int node , string & x ) {
        if ( vis[node] ) return ;
        vis[node] = true ; 
        for( auto & i : adj[node] ) dfs(i,x);
        line(node,x);
        joint(node,x);
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n = s.size() ;
        for( int i = 1 ; i < parent.size() ; i++ ) {
            int j = parent[i]; 
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        dfs(0,s);
        return ans ; 
    }
};



// ######################################################
// Solution 1 : TLE version , base solution :) 
// ######################################################

class Solution {
public:
    static const int N = 1e5 ; 
    vector<int> adj[N+5] ;
    bool vis[N+5] = {0};
    int path[N+5] = {0};
    int ans = 1 ;

    bool canJoin( int b , int a , int c , string & x ){
        return ( x[a] != x[b] && x[a] != x[c] );
    }
    void joint( int parent , string & x ) {
        int m = adj[parent].size();
        int jointPath = 0 ;  
        for( int i = 0 ; i < m ; i++ ) {
            for( int j = i+1 ; j < m ; j++ ) {
                int childA = adj[parent][i] , childB = adj[parent][j] ;
                if ( canJoin( childA , parent , childB , x) )  {
                    jointPath = max ( jointPath , path[childA] + path[childB] + 1 ) ; 
                }
            }
        }
        ans = max ( ans , jointPath ) ; 
        return; 
    }

    void line( int parent , string & x ){ 
        path[parent] = max( path[parent] , 1 ); 
        for( auto &child : adj[parent] ) {
            if ( x[parent] == x[child] ) continue ;
            path[parent] = max( path[parent] , path[child] + 1 );
        }
        ans = max( ans , path[parent] ) ; 
        return ; 
    }

    void dfs( int node , string & x ) {
        if ( vis[node] ) return ;
        vis[node] = true ; 
        for( auto & i : adj[node] ) dfs(i,x);
        line(node,x);
        joint(node,x);
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n = s.size() ;
        for( int i = 1 ; i < parent.size() ; i++ ) {
            int j = parent[i]; 
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        dfs(0,s);
        return ans ; 
    }
};


