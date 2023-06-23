class Solution {
public:
    static const int N = 1000;
    static const int M = 1000;
    static const int OFFSET = 500;
    int arr[N+1][M+1]; // leave space to offset negatives
    
    int longestArithSeqLength(vector<int>& nums) {
        int mx = 0 ;
        for( int i = 0 ; i < nums.size() ; i++ ){
            for ( int j = 0 ; j < i ; j++ ){
                int curr = nums[i] , lst = nums[j] , diff = (curr - lst) + OFFSET ;
                if( arr[j][diff] ) {
                    arr[i][diff] = arr[j][diff] + 1;
                }
                else {
                    arr[i][diff] = 2;
                }
                mx = max( arr[i][diff] ,  mx );
            }
        }
        return mx;
    }
};
