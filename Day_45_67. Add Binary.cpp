class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size() , m = b.size() ; 
        string ans( max(n,m) , '0' );
        int len = max(n,m) ;
        int carr = 0 ; 
        for( int i = n-1 , j = m-1 , k = len-1 ; i >= 0 || j >= 0 ; i-- , j-- , k-- ){
          if ( i < 0 ) {
              if ( carr ){
                if( b[j] == '0' ) ans[k] = '1' , carr = 0;
                else ans[k] = '0' ; 
              }
              else ans[k] = b[j] ;
          }
          else if ( j < 0 ){
              if ( carr ){
                if( a[i] == '0' ) ans[k] = '1' , carr = 0;
                else ans[k] = '0' ; 
              }
              else ans[k] = a[i] ;
          }
          else {
            if (!carr){
               if ( a[i] != b[j] ) ans[k] = '1' ;
               else if ( a[i] == '1' ) carr = 1 ; 
            }
            else {
               if ( a[i] != b[j] ) ans[k] = '0'; 
               else if ( a[i] == '1' ) ans[k] = '1';
               else if ( a[i] == '0' ) ans[k] = '1',carr = 0;
            }
          }
        }
        return ( carr ? "1"+ans : ans ) ;
    }
};
