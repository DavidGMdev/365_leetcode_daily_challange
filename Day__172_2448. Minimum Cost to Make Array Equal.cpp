typedef long long ll ;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        // try all possible elements in array 
        // solve equation mathimatically on paper first
        int n = nums.size(); 

        // preprocess
        vector<pair<int,int>> spare(n) ;
        for( int i = 0 ; i < n ; i++ ) spare[i] = {nums[i],cost[i]};
        sort(spare.begin(),spare.end());
        for( int i = 0 ; i < n ; i++ ) {
            nums[i] = spare[i].first;
            cost[i] = spare[i].second;
        }

        // precalculations 
        vector<ll> pre_mul(n) , pre_cost(n);
        for ( int i = 0 ; i < n ; i++ ){
            
            // pre_mul [ term 1 ]
            ll curr = nums[i] * 1ll * cost[i];
            if(!i) pre_mul[i] = curr;
            else pre_mul[i] = pre_mul[i-1] + curr ;

            // pre_cost [ term 2 ]
            if(!i) pre_cost[i] = cost[i];
            else pre_cost[i] = pre_cost[i-1] + cost[i] ;

        }
        ll ans = LLONG_MAX;
        // brute force solution between all possible values of nums 
        for( int i = 0 ; i < n ; i++ ){
            ll a = (nums[i]*pre_cost[i]) - (pre_mul[i]);
            ll b = (pre_mul[n-1] - pre_mul[i]) - (nums[i]*(pre_cost[n-1] - pre_cost[i]));
            ans = min( ans , a+b );
        }
        return ans;
    }
};
