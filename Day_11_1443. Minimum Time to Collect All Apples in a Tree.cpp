// ##############################################
// Main Idea :::
// ##############################################

// each parent node feed on it's children nodes state 
// child nodes supply their parent's with true state ( in hasApple state )  
// state[parent] |= state[child]
// [ edge case ] take care that this only in case the child is univisited yet to avoid parent to child supply [ inverted one ]
// and so on along the path 
// go and mark all those supplied nodes along paths
// now we have a vector hasApple store nodes states 
// counting all true state = { all nodes having apples or supplied by a descendant supplied or having apple }
// those gives us m nodes
// those m nodes are strongly connected forming a subtree ( spanning tree )
// to connect those forming a tree we must have m-1 edges 
// having m-1 edges tree E = m-1 
// and each edge traversed 2 times each consumes one unit time 
// time result = 2*E = ( 2 * ( m-1 ) )
// [ edge case ] in case we have no apples at all keep it zero no calculations 


class Solution {
public:
    static const int N = 1e5 ;
    vector<int> adj[N+1] ; 
    bool vis[N+1] = {0}; 
    int ans = 0;
  
    void dfs( int node , vector<bool> & has ) {
        if ( vis[node] == true ) return;
        vis[node] = true ; 
        for( auto &i : adj[node] ){
            bool flg =  vis[i] ; 
            dfs(i,has);
            if (has[i] && !flg) has[node] = true ; 
        }
    }
  
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for( int i = 0 ; i < edges.size() ; i++ ) {
            adj[ edges[i][0] ].push_back( edges[i][1] );
            adj[ edges[i][1] ].push_back( edges[i][0] );
        }
        dfs(0,hasApple);
        for( int i = 0 ; i < n ; i++ ) ans += (hasApple[i] ? 1 : 0) ;
        if ( ans ) ans = (ans-1)*2 ;
        return ans ; 
    }
  
};


