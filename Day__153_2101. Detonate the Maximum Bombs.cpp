class Solution {
public:
    int dfs(int bomb , vector<vector<int>>& adj , vector<bool> &vis ){
        int ret = 0; 
        if( vis[bomb] ) return ret ;
        vis[bomb] = true;
        for(auto & child : adj[bomb] ){
            ret += dfs(child,adj,vis);
        }
        return ret + 1;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size() ; 
        vector<vector<int>>adj(n);
        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if( i == j ) continue ; 
                double dist_sqr = (bombs[i][0] - bombs[j][0])*1.0*(bombs[i][0] - bombs[j][0])+ (bombs[i][1] - bombs[j][1])*1.0*(bombs[i][1]-bombs[j][1]) ;
                if( dist_sqr <= bombs[i][2]*1.0*bombs[i][2] ){
                    adj[i].push_back(j);
                }
            }
        }
        int mx = 1; 
        for( int i = 0 ; i < n ; i++ ){
            vector<bool> vis(n,false);
            int ret = dfs(i,adj,vis); 
            mx = max( mx , ret);
        }
        return mx;
    }
   
};

// for( auto i : adj ){
//             for( auto j : i ){
//                 cout << j << " " ;
//             }
//             cout << endl;
//         }
