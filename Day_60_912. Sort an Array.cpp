class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        const int N = 1e5;
        const int offset = 5e4;
       int freq[N+1] = {0} ;
        for ( auto &i : nums ){
            freq[i+offset]++;
        }
        for ( int i = 0 , j = 0 ; i <= N && j < nums.size() ; i++ ){
            while(freq[i]--){
                nums[j++] = i - offset ;
            }
        }
        return nums;
    }
};
