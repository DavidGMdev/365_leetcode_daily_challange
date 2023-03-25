/*

NICE problem 
---------------------

- idea of extracting number of components from given graph , we can use a traversal algorithm or union find to do this step
- on having size of each seprable components we need to calculate number of pairs 
- Note : we take pairs as combination not permutation , {a,b} is same as {b,a}
- let sizes are n1 , n2 , n3 , n4 , ..etc 
- number of pairs = n1*n2 + n1*n3 + n1*n4 + n2*n3 + n2*n4 + n3*n4 
- to calculate this in naive way we need n^2 step where n is number of components [ cannot fit , worst case each component is one node means 1e5 component ]
- we need it in at most n , let's simplify the equation 
- n1*n2 + n1*n3 + n1*n4 + n2*n3 + n2*n4 + n3*n4  = n1*(n2+n3+n4) + n2*(n3+n4) + n3*(n4) 
- the idea it to accmulate total at begin ( n1 + n2 + n3 + n4 )
- loop on n components sizes , at each size subtract it and then multiply by the reminder after subtraction 

*/

// #################################
// Using DFS 
// #################################


typedef long long ll ;
class Solution {
public:

    void dfs( int node , vector<vector<int>> & adj , vector<bool> & vis , int &len ){
        if ( vis[node] ) return ;
        vis[node] = true;
        len++;
        for( auto & child : adj[node] ) dfs(child,adj,vis,len);
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        // divide into components [ dfs , bfs , or DSU ..etc ]
        // where n is size of components n1,n2,n3,..etc
        // try dfs
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        for( auto & edge : edges ){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> components(n,0);
        ll total_len = 0 ;
        for( int i = 0 , j = 0 ; i < n ; i++ ){
            int len = 0 ;
            dfs(i,adj,vis,len);
            components[j++] = len;
            total_len += len ;  
        }
        ll ans = 0 ;
        for( int i = 0 ; i < n ; i++ ){
            total_len -= components[i];
            ans += ( total_len * components[i] );
        }
        return ans ;  
    }
};
