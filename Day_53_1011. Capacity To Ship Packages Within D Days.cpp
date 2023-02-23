class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1 , r = 1e8 ;
        l = *max_element(weights.begin(), weights.end() );
        int ans = INT_MAX;
        while( l <= r){
            int m = (l+r)/2;
            int dd = 1;
            for(int i = 0 , sum = 0 ;i < weights.size() ;i++){
                if(sum+weights[i]<=m){
                    sum += weights[i];
                }
                else{
                    sum = weights[i];
                    dd++;
                }
            }
            if(dd<=days){
               r =  m-1;
               ans = min (ans,m);
            }
            else{
               l = m+1;
            }
        }
        return ans;
    }
};
