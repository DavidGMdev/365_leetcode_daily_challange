class Solution {
public:
    static const int N = 200 , M = 200 ;
    int dp[N+1][M+1] ;
    void bfs( pair<int,int> src , vector<vector<int>>& grid ){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q; 
        q.push(src);
        dp[src.first][src.second] = grid[src.first][src.second] ; 
        while( !q.empty() ){
            auto curr = q.front();
            q.pop();
            
            int r = curr.first ; 
            int c = curr.second;
            
            // right 
            if ( c + 1 < m && dp[r][c] + grid[r][c+1] < dp[r][c+1] ){
                q.push({r,c+1});
                dp[r][c+1] = dp[r][c] + grid[r][c+1] ; 
            }
            // down 
            if ( r + 1 < n && dp[r][c] + grid[r+1][c] < dp[r+1][c] ){
                q.push({r+1,c});
                dp[r+1][c] = dp[r][c] + grid[r+1][c] ; 
            }
        }

    }
    int minPathSum(vector<vector<int>>& grid) {
        for ( int i = 0 ; i <= N ; i++ ) 
            for ( int j = 0 ; j <= M ; j++ ) 
                dp[i][j] = INT_MAX;
        bfs({0,0},grid);
        int n = grid.size();
        int m = grid[0].size();
        return dp[n-1][m-1];
    }
};
