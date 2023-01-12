// ################################################
// Solution 
// ################################################


// similar idea as the previous day challange 
// state of node here is described as frequancy of each char a to z [ all are lower case chars ]
// state totally is the prefix frequnacy of a char ( bottom to up )( all below subtree ) for a specific node 
// the parent nodes feed on their children states
// ( (state[parent] = state[parent] + state[child]) for all children ) for all chars a to z 
// state[parent][char] = state[parent][char] + summation( state[child][char] ) 
// this done through relaxation method ( relax function )
// relax function ( update parent state with it's child state )
// this works in some manner like prefix frequancy for all chars from bottom to top ( leaves to root )
// along all paths      
// now before ending call of a node it's state will be updated with all states of it's lower subtree 
// lower subtree = all descendents
// if (!vis) condition ? 
// // make sure to avoid parent to child supply state 
// // can also be solved by change the position of marking node as visited 



class Solution {
public:
    static const int N = 1e5 ; 
    vector<int> adj[N+1] ;  
    bool visited[N+1] = {0};
    int freq[N][26] = {0} ; 
    vector<int> ans ; 

    void relax( int parent , int child ) {
        for( int i = 0 ; i < 26 ; i++ ) freq[parent][i] += freq[child][i] ; 
    }
    
    void dfs( int node , string & labels , vector<int> & ans ){
        if( visited[node] ) return ; 
        visited[node] = true ; 
        freq[node][labels[node]-'a']++;
        for ( auto & i : adj[node] ) {
            bool vis = visited[i] ;
            dfs(i,labels,ans);
            if (!vis) relax(node,i);
        }
        ans[node] = ( freq[node][labels[node]-'a'] ) ;
        return ;  
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int>ans(n) ; 
        for( int i = 0 ; i < edges.size() ; i++ ) {
            adj[ edges[i][0] ].push_back( edges[i][1] ) ; 
            adj[ edges[i][1] ].push_back( edges[i][0] ) ; 
        }
        dfs(0,labels,ans) ; 
        return ans ;
    }
};


