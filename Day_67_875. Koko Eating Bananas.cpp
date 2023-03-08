typedef long long ll ;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // bs ?
        int l = 1 , r = 1e9 ;
        while ( l <= r ){
            int mid =  l+(r-l)/2;
            ll time = 0 ; 
            for( int i = 0 ; i < piles.size() ; i++ ){
                time += piles[i]/mid;
                time += ( piles[i] % mid ? 1 : 0 ) ;
            }
            if( time <= h ) r = mid - 1 ;
            else l = mid + 1 ;
        }
        return l ;
    }
};
