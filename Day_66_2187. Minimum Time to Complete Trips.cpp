class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 0 , r = 1e14 ; 
        while ( l <= r ){
            long long mid = (l+r)/2;
            long long done = 0 ; 
            for(auto &i : time){
                 done += (mid)/(i*1ll) ;
            }
            if( done >= totalTrips ) r = mid-1;
            else if ( done < totalTrips ) l = mid+1;
        }
        return l;
    }
};
