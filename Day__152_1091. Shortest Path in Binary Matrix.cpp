class Solution {
public:
    const int dx[8] = {-1,-1,0,1,1,1,0,-1};
    const int dy[8] = {0,1,1,1,0,-1,-1,-1};

    int bfs( pair<int,int> src , pair<int,int> trg , vector<vector<int>>& grid ){
        if( grid[src.first][src.second] || grid[trg.first][trg.second] ) return -1;
      
        int n = grid.size();
      
        queue<pair<int,int>> q;
        q.push(src);
        grid[src.first][src.second] = -1 ;
      
        int dist = 1 ; 
      
        while(!q.empty()){
            int len = q.size(); // size of this level
            while(len--){
                auto curr = q.front();
                q.pop();
                if( trg == curr ) return dist; // important in edge case : src == trg : in 1x1 matrix
                for( int i = 0 ; i < 8 ; i++ ){
                    int nr = curr.first  + dx[i] , nc = curr.second + dy[i];
                    if( nr < n && nc < n && nr > -1 && nc > -1 && !grid[nr][nc] ){
                        if( make_pair(nr,nc) == trg ) return dist + 1; // prune 
                        q.push({nr,nc});
                        grid[nr][nc] = -1 ; // implicit grid visit
                    }
                }
            }
            dist++;
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() ;
        return bfs({0,0},{n-1,n-1},grid);
    }
};
