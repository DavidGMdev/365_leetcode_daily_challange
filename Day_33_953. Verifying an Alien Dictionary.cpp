class Solution {
public:
    bool ok( string &x , string &y , vector<int>& w ){
        for( int i = 0 ; i < min( x.size() , y.size() ) ; i++ ) {
            if ( w[ x[i] - 'a' ]  == w[ y[i] - 'a' ] ) continue ;
            if ( w[ x[i] - 'a' ]  >  w[ y[i] - 'a' ] ) return false ;
            else return true ;
        }
        if ( x.size() > y.size() ) return false ;
        else return true ;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>w(26,0);
        for( int i = 0 ; i < order.size() ; i++ ) w[ order[i] - 'a' ] = i ; // weights
        int n = words.size() ;
        for( int i = 0 ; i < n ; i++ ){
            for ( int j = i+1 ; j < n ; j++ ){
                if( !ok( words[i] , words[j] , w ) ) return false;
            }
        }
        return true ; 
    }
};
