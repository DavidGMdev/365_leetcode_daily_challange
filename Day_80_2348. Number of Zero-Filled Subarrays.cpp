typedef long long ll ;

class Solution {
public:
    ll calc( ll len ) {
        return (len*(len+1))/2 ; // sumseries 1+2+3+...n ( since contiguous condition )
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size() , i = 0 ; 
        ll ans = 0 ;
        while(i < n){
            if(!nums[i]){
                int j = i ;
                while(j < n && !nums[j]) j++;
                ans += calc(j*1ll-i*1ll);
                i = j ;
            }
            else i++;
        } 
        return ans ;
    }
};
