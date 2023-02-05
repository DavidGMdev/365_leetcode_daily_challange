class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0) , state(26,0);
        int n = s1.size(), m = s2.size() , i = 0 , j = -1 ;
        for( int i = 0 ; i < n ; i++ ) {
            freq[ s1[i] - 'a' ]++;
            // init state 
            if( i < m ) state[ s2[i] - 'a' ]++ ;
        }
        // testing all possible windows 
        for( int i = 0 , j = n - 1 ; i <= m-n ; i++ , j++ ){
            if ( state == freq ) return true ;
            state[ s2[i] - 'a'  ]--; 
            if( j+1 < m ) state[ s2[j+1] - 'a']++;
        }
        return false ; 
    }
};
