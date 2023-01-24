class Solution {
public:
    static const int len = 400;
    static const int OO = 0x3f3f3f3f;
    int dist[len+5];
    int tp[len+5];
    bool vis[len+5];
    int ans = -1 ; 

    void bfs( int x , int n ){
        queue<int> q;
        q.push(x);
        dist[x] = 0;
        while ( !q.empty() ){
            int curr = q.front();
            q.pop();
            vis[curr] = true;
            if ( curr == n*n ) {
                ans = dist[curr] ; 
                return ;
            }
            // edge by formula
            for ( int i = 1 ; i <= 6 ; i++ ) {
                int nxt = curr + i ;
                if( nxt > n*n ) continue ;
                if ( tp[nxt] != -1 ) nxt = tp[nxt];
                if (!vis[nxt]) {
                    vis[nxt] = true;
                    q.push(nxt);
                    dist[nxt] = dist[curr] + 1 ; 
                }
            }
        }
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        for ( int i = 1 ; i <= len ; i++ ) dist[i] = OO;
        int n = board.size(); 
        for ( int i = n-1 , cnt = 1 , flg = 0 ; i >= 0 ; i-- ) {
            for( int j = 0   ; j < n  && !flg ; j++ ) tp[cnt++] = board[i][j] ;
            for( int j = n-1 ; j >= 0 && flg  ; j-- ) tp[cnt++] = board[i][j] ;
            flg^=1;
        }
        bfs(1,n);
        return ans ;
    }
};

// for ( int i = 1 ; i <= len; i++ ) {
//     cout << i << " " <<  tp[i] << endl ;
// }
