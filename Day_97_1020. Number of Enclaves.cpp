// same as previous day xD , use same code with little modifications 
class Solution {
public:
    const int dx[4] = {1,0,-1,0};
    const int dy[4] = {0,1,0,-1};
    int bfs( pair<int,int> src , vector<vector<int>>& grid ) {
        int n = grid.size() , m = grid[0].size();
        queue<pair<int,int>> q ; 
        q.push(src);
        grid[src.first][src.second] = -1 ;
        bool flg = false ; 
        int cnt = 0 ; 
        while(!q.empty()){
            cnt++;
            auto curr = q.front();
            q.pop();
            for ( int i = 0 ; i < 4 ; i++ ){
                pair<int,int> nw = { curr.first + dx[i] , curr.second + dy[i] } ;
                if( nw.first <= -1 || nw.first >= n || nw.second <= -1 || nw.second >= m ) flg = true;
                if( nw.first > -1 && nw.first < n && nw.second > -1 && nw.second < m &&  grid[nw.first][nw.second] == 1 ){
                    q.push(nw);
                    grid[nw.first][nw.second] = -1;
                }
            }
        }
        if(flg) cnt = 0 ; 
        return cnt ;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0 ; 
        int n = grid.size() , m = grid[0].size();
        for( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ){
                if( grid[i][j] != 1 ) continue ; 
                ans+= bfs({i,j},grid);
            }
        }
        return ans;
    }
};
