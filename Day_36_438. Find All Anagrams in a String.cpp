class Solution {
public:
    
    // fortunately xD , Anagram itself is a meaning that describe a "permutation" of string 
    // so we can make use of the 2-pointers idea of the previous problem 
    // and that's it.
  
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq(26,0) , state(26,0) , ans ;
        int n = p.size(), m = s.size() , i = 0 , j = -1 ;
        for( int i = 0 ; i < n ; i++ ) {
            freq[ p[i] - 'a' ]++;
            // init state 
            if( i < m ) state[ s[i] - 'a' ]++ ;
        }
        // testing all possible windows 
        for( int i = 0 , j = n - 1 ; i <= m-n ; i++ , j++ ){
            if ( state == freq ) ans.push_back(i);
            state[ s[i] - 'a'  ]--; 
            if( j+1 < m ) state[ s[j+1] - 'a']++;
        }
        return ans; 
    }
};
