// ######################################################
// main idea
// ######################################################

/*
the main idea here is that parent node feed on their children nodes results ,
where each parent recives values from children and build on it it's own result 

at each node we make descion of that we have two possible ways ?

= construct a straight path and continue to the next [ upper ] parent
>>> with the max path it recives from it's children +1
>>> and path it to it's parent 


= construct a bended path , that this node will be the joint of it /\
>>>> with the max 2 paths it recives from it's children +1 

*/

// ######################################################
// Solution 4 : most optimized  
// ######################################################

class Solution {
public:
    // make it directed only parent => child relation 
    // no need to visited     => as it's directed tree now
    // no need to path array  => replace using dfs func retruns 
    int ans = 1 ; 
    int dfs( int node , const vector<int> adj[] , const string & s ){
        int l = 0 , r = 0 ;
        for ( auto &child : adj[node] ) {
            int res = dfs(child,adj,s);
            if ( s[node] == s[child] ) continue ; 
            if (res >= l) r = l , l = res ;
            else if ( res > r ) r = res ; 
        }
        // we gurantee l ,r as max "possible to link" children 
        // possible cases = { l+1 , r+1 , l+r+1 } = { l+r+1 } always satisfy the max 
        ans = max(ans,l+r+1) ; 
        
        // only return the longest straight path 
        return l+1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        vector<int> adj[n] ; 
        for( int i = 1 ; i < n ; i++ ) adj[ parent[i] ].push_back(i); // directed from parent to child 
        dfs(0,adj,s);
        return ans; 
    }
};

/*

////////////////////////
what OPTIMIZATION ? 
///////////////////////


-------------------------
### memory level 
-------------------------

= use just directed graph style [ parent -> child ]
>>>> remove useless u to v , v to u  complixity 
>>>> remove useless visited array , since no way to have cycles now 

= make use of function return 
>>>> remove useless path[] , 
that store child response for just path it to parent after call end ,
just use the function return and pass the value ON THE FLY to node parent 


= move adjacency list to main and pass as refrence in param 
>>>> solve wastage of adj[N] , max memeory declared for all testcases regaradless actual size 

all this opt, make diffrence in exection time and get high beat in submission time , memeory beat %

and that's it <3


*/

/*

/////////////////////////
Nice Hint ::
/////////////////////////

[ Accepted ]
int res = dfs(child,adj,s);
if ( s[node] == s[child] ) continue ;

vs 

[ Wrong Answer ]
if ( s[node] == s[child] ) continue ;
int res = dfs(child,adj,s);

why ? xd 
simply the unlucky one whose parent is adjacent with ,
will STARVE totally and all it's children subtree ,
as here in directed tree no way to node else it's parent 
so the lastest code results a totally un discovered subtrees in some cases 

[ take care ]
[ think twice , code once ]


*/

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


