// nice application on implicit graphs problems 
// reprsent equations as graph interconnected together 
// evaluate by dfs traversal from varaible to another 

class Solution {
public:
    unordered_map<string,bool>vis;
    map<string,vector<pair<string,double>>> adj ;
    double dfs( string curr , string target , double res ){
        if( curr == target ) return res ;
        if( vis[curr] ) return -1.0 ;
        vis[curr] = true;
        for( auto edge : adj[curr] ){
            double sub = dfs(edge.first,target,res*edge.second);
            if( sub != -1.0 ) return sub;
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for( int i = 0 ; i < equations.size() ; i++ ){
            string l = equations[i][0] , r = equations[i][1];
            double lr_eval = values[i] ;
            double rl_eval = 1.0/values[i] ; 
            adj[l].push_back({r,lr_eval});
            adj[r].push_back({l,rl_eval});
        }
        vector<double> res ; 
        for( int i = 0 ; i < queries.size() ; i++ ){
            string l = queries[i][0];
            string r = queries[i][1];
            if( adj.find(l) == adj.end() || adj.find(r) == adj.end() ){
                res.push_back(-1.0);
                continue;
            }
            double calc = dfs(l,r,1.0);
            res.push_back(calc);
            vis.clear();
        }
        return res;
    }
};
