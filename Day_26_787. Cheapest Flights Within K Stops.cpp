class Solution {
public:
    static const int OO = 0x3f3f3f3f ;
    static const int N = 100 ;
    int dist[N+5]  ;
    int bfs( int src , int dst , int k , vector<vector<vector<int>>> & adj ){
        queue<vector<int>> q; // [ current , moves , accmulative ]
        q.push({src,0,0}); // init  
        int ans = OO ;
        while (!q.empty()){
            vector<int> curr = q.front();
            q.pop();
            for (auto edge : adj[curr[0]] ){ // edge [ to , weight ]
                vector<int> nxt = {edge[0],curr[1]+1,curr[2]+edge[1]} ;
                // this was a cause of TLE  ::: push only in case we may minimize else "NO"
                if ( dist[nxt[0]] > nxt[2] && nxt[1] <= k+1 ){ 
                    dist[nxt[0]] = nxt[2] ; 
                    q.push(nxt) ;
                } 
            }
        }
        return ( dist[dst] == OO ? -1 : dist[dst] ) ; 
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<vector<int>>> adj(n);
       for ( int i = 0 ; i <= N ; i++ ) dist[i] = OO; // init OO
       for( int i = 0 ; i < flights.size() ; i++ ) {
           adj[ flights[i][0] ].push_back({ flights[i][1] , flights[i][2] });
       }
       return bfs(src,dst,k,adj);
    }
};
