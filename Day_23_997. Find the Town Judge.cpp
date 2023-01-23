class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        const int N = 1e3 ; 
        int in = 0 , out = 1 , deg[N][2]={0} ; 
        for( int i = 0 ; i < trust.size() ; i++ ) {
            trust[i][0]-- , trust[i][1]--;
            deg[trust[i][0]][out]++; // outDegree
            deg[trust[i][1]][in]++; // inDegree
        }
        for( int i = 0 ; i < n ; i++ ){
            if ( !deg[i][out] && deg[i][in] == n-1 ) return i+1 ; 
        }
        // no need to check for multiple town judges exist 
        // where all cannot satisfy n-1 inDegree ;) and zero outDegree similtinously
      
        return -1 ;
    }
};


