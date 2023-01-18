typedef long long ll ; 

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // kadane's algorithm based solution 
      
        int n = nums.size();
        ll mxlocal = INT_MIN , mxglobal = INT_MIN ;
        ll mnlocal = INT_MAX , mnglobal = INT_MAX ;
        ll accmulate = 0 ; 
        for( int i = 0 ; i < n ; i++ ) {
            // max kadane's 
            mxlocal  = max( nums[i]*1ll , nums[i] + mxlocal ) ; 
            mxglobal = max( mxlocal , mxglobal );
            
            // min kadane's 
            mnlocal  = min( nums[i]*1ll , nums[i] + mnlocal ) ; 
            mnglobal = min( mnlocal , mnglobal );

            accmulate += nums[i] ;
        }
      
        // edge case of all negatives 
        // just pick the best one using max kadane 
        if ( accmulate == mnglobal ) {
            return mxglobal ; // max is the least -ve one 
        }
        else {
            return max( mxglobal*1ll , accmulate - mnglobal );
            // maximize the answer on  
            // take the general maximum [ normal way ] 
            // take the accmulate without the minimum most sub array part [ circular behaviour ]
        }
    }
};
