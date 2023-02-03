class Solution {
public:
    string convert(string & s, int & numRows) {
        int n = s.size() , m = numRows , l = 0 ;
        vector<string> grid(m) ;
        while( l < n ){
            for(int i = 0 ; l < n && i < m ; i++,l++ ) grid[i] += s[l];
            for(int i = m - 2 ; i > 0 && l < n ; i-- , l++ ) grid[i] += s[l];
        }
        string ans = ""; 
        for ( int i = 0 ; i < m ; i++ ) ans += grid[i] ;
        return ans ;
    }
};



