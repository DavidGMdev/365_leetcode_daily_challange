typedef long long ll ; 

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n,0); // ans
        vector<pair<int,int>> v(n); // spell value and idx 
        for( int i = 0 ; i < n ; i++ ) v[i] = { spells[i] , i };
        sort( v.begin() , v.end() , greater<>() );
        sort( potions.begin() , potions.end() ) ;
        for( int i = 0 , j = 0 ; i < n ; i++ ){
            ll element = v[i].first ; 
            int idx = v[i].second;
            while( j < m && element * (potions[j]*1ll) < success  ) j++ ;
            ans[idx] = m-j; 
        }
        return ans ;
    }
};
