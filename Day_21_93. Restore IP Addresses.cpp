class Solution {
public:
    vector<string> possible ;
    bool check( int p1 , int p2 , int p3 , string & x ){
        string tot = "" , spare = "" ; 
        int n = x.size() , m = 4 ;
        int st[] = {  0 , p1 , p2 , p3 } ; 
        int en[] = {  min(n,p1) , min(n,p2) , min(n,p3) , n } ;
        for ( int i = 0 ; i < m ; i++ ) {
            for( int j = st[i] ; j < en[i] ; j++ ) spare += x[j];
            if ( !(spare != ""  && spare.size() <= 3 && stoll(spare) < 256 && to_string(stoll(spare)).size() == spare.size() )  ) return false ;
            tot += spare + ( i == m-1 ?  "" : "." ) ;
            spare = "";
        }
        possible.push_back(tot);
        return true ; 
    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        for ( int i = 1 ; i < n + 3 ; i++ ){
            for ( int j = i+1 ; j < n + 3 ; j++ ){
                for( int l = j+1 ; l < n + 3 ; l++ ) {
                    check(i,j,l,s);
                }
            }
        }
        return possible ;
    }
};
