class Solution {
public:
    static const int MOD = 1e9+7 ;
    static const int N = 1e5;
    int memo[N+1];
    int rec(int len , int low , int high , int zero , int one ){
        if( len > high ) return 0;
        if( memo[len] != -1 ) return memo[len];
        int ret = 0 ;
        if( len <= high && len >= low ) ret = 1 ;
        int ans = ( ret + (rec(len+zero,low,high,zero,one)%MOD) + (rec(len+one,low,high,zero,one)%MOD) ) % MOD;
        return memo[len] = ans;        
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        for( int i = 0 ; i <= high ; i++ ) memo[i] = -1;
        return rec(0,low,high,zero,one);
    }
};
