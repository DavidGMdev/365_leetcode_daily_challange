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

/*

Testcase contribute :::

spare.size() <= 3 
old solution without this condition
got AC instead of RE verdict 
must got RE due to using stoll on 20 digit string in worst case 

I contribute the testcase to Leetcode and got 100 Coin :)

testcase here : 
on input "99999999999999999999" or any large samples ,

issue here : [ISSUE](https://github.com/LeetCode-Feedback/LeetCode-Feedback/issues/11189)

how to fix :
just make sure of each partiton not exceeding 
long long limit or even 3 digits maximum for 
this problem satatement 

==> spare.size() <= 3 

and also may do more optimizations 
in for loop generating indexes to avoid usless checks
or in begin of the function to check is those partations valid sized partitions or not 

*/

