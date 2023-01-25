class Solution {
public:
    static const int N = 1e5 ;
    static const int OO = 0x3f3f3f3f ; 
    vector<int> adj[N+5] ;
    bool vis[N+5] = {0} ;
    int dist[N+5][2];
    
    void dfs(int parent , int label , int i , int cost ){
        if (vis[i]) return;
        vis[i] = true;
        dist[i][label] = min( cost , dist[i][label] ) ;
        for (auto j : adj[i]) dfs(parent,label,j,cost+1);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2){
        for( int i = 0 ; i <= N ; i++ ) {
            dist[i][0] = dist[i][1] = OO ; // init dist 
        }
        for( int i = 0 ; i < edges.size() ; i++ ) {
            if( edges[i] != -1 ) adj[i].push_back(edges[i]);
        }
        dfs(node1,0,node1,0);
        memset(vis,0,sizeof(vis));
        dfs(node2,1,node2,0);

        int ans = -1 , mn = OO ; 
        for ( int i = 0 ; i <= N ; i++ ) {
            if ( max( dist[i][0] , dist[i][1] ) < mn ) {
                ans = i ;
                mn = max( dist[i][0] , dist[i][1] );
            } 
        }

        return ans ;
    }
};


