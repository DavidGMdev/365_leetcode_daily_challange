class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carr = 0 , n = num.size(); 
        vector<int> ans; 
        for( int i = n-1 , fct = 10 ; i >= 0 || k ; i-- ){
            int dig = k%fct; 
            k/= fct ;
            if( i < 0 ) {
                dig += carr;
                if( dig > 9 ){
                    dig%= 10;
                    carr= 1;  
                }
                else {
                    carr = 0;
                }
                ans.push_back(dig);
            }
            else if( k < 0 ) {
                num[i] += carr;
                if( num[i] > 9 ){
                    num[i]%= 10;
                    carr= 1;  
                }
                else {
                    carr = 0;
                }
                ans.push_back(num[i]);
            }
            else {
                num[i] += dig + carr ;
                if( num[i] > 9 ){
                    carr = 1 ;
                    num[i] %= 10 ; 
                }
                else carr = 0 ; 
                ans.push_back(num[i]);
            }
        }
        if (carr) ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans ; 
    }
};
