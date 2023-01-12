// ################################################
// Solution 
// ################################################

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


