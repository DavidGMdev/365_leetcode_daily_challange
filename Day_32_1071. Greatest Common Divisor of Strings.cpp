class Solution {
public:
    bool isDivisible( string & x , string & y ){
        int n = x.size() , m = y.size() ;
        int i = 0 ;
        for(; i < n; i++){
            if ( x[i] != y[i%m] ) return false ;
        }
        return ( i%m == 0 ) ;
    }
    string gcdOfStrings(string str1, string str2) {
        if( str1.size() < str2.size() ) swap( str1 , str1 );
        // str2 always have minimum length
        int n = str2.size();
        string ans = "" , slice = ""; 
        for( int i = 0 ; i < n ; i++ ){
            slice += str2[i];
            if( isDivisible(str1,slice) && isDivisible(str2,slice) && slice.size() > ans.size() ) ans = slice ;
        }
        return ans;
    }
};
