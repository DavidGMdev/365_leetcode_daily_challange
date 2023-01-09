class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int station = 0 , accmulate = 0 , n = gas.size() ; 
        int idx = 0 ; 
        for( int i = 0 ; i < n ; i++ ) {
            station += ( gas[i] - cost[i] ) ; 
            if( station < 0 ){
                idx = i+1 ;
                accmulate += station ; 
                station = 0 ; 
            }
        }
        return ( station + accmulate >= 0 ? idx : -1 ) ;
    }
};
