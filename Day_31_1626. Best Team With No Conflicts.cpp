class Solution {
public:
    static const int N = 1e3 ; 
    int memo[N+5][N+5] ;
    vector<vector<int>> v;
    // i is the current 
    // j is the most recent picked [ previous ]
    int dp(int j, int i) {
        if (i >= v.size()) return 0;
        if (memo[j+1][i] != -1) return memo[j+1][i];

        if (j == -1 || v[i][1] >= v[j][1] ) {
            return memo[j+1][i] = max(
                dp(i , i + 1) + v[i][1], // pick , then update previous to be the picked 
                dp(j , i + 1) // leave 
            );
        }
        return memo[j+1][i] =  dp(j, i+1); // leave 
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        for (int i = 0; i < scores.size(); i++) v.push_back({ages[i], scores[i]});
        sort(v.begin(), v.end());
        for( int i = 0 ; i <= N ; i++ ) for ( int j = 0 ; j <= N ; j++ ) memo[i][j] = -1 ;
        return dp(-1,0);
    }
};
