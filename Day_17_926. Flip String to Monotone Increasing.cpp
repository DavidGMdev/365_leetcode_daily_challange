class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int pre[n];
        for( int i = 0 ; i < n ; i++){
            int val = ( s[i] == '1' ? 1 : 0 ) ; 
            if (!i) pre[i] = val;
            else pre[i] = pre[i-1] + val; 
        }
        int idx = -1 , mn = n - pre[n-1] ; 
        for ( int i = 0 ; i < n ; i++ ) {
            int preOnes , postOnes , convertToZeros , convertToOnes , cost ;
            preOnes = pre[i];
            postOnes = pre[n-1] - pre[i];
            convertToZeros = pre[i] ;
            convertToOnes = (n-(i+1)) - (pre[n-1] - pre[i]);
            cost = ( convertToZeros + convertToOnes ); // convert to zero + convert to ones 
            if ( cost < mn ) idx = i , mn = cost ;
        }
        return mn; 
    }
};
