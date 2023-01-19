typedef long long ll ; 
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size() ;
        map<int,int>mp;
        mp[0] = 1 ; // base case for k "actually" found in array [ single elements that already divisible by k ]
        ll ans = 0 ;
        for( int i = 0 ; i < n ; i++ ) {
            if(i) nums[i] += nums[i-1] ;
            int md = nums[i]%k ; // get the mod of the prefix at current idx 
            if( md < 0 ) md += k ; // whole new cycle to avoid negative modulo
            ans += mp[md] ; // can link with all the previous matched reminders  
            mp[md]++; 
        }
        return ans ;
    }
};
