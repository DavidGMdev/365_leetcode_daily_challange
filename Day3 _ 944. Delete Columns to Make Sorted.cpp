class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt = 0 ; 
        for( int j = 0 ; j < strs[0].size() ; j++ ){
            for( int i = 1 ; i < strs.size() ; i++ ) {
                if( strs[i][j] - 'a' >= strs[i-1][j] - 'a' ) continue ;
                cnt++ ; break ;
            }
        }
        return cnt ;
    }
};
