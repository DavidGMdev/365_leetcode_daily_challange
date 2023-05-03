class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        const int N = 2e3;
        int freq[N+5] = {0};
        int offset = 1000;
        for (auto & i : nums1){
            int idx = i + offset;
            freq[idx] = 1;
        }
        for (auto & i : nums2){
            int idx = i + offset;
            if( freq[idx] == 1 ) freq[idx] = 3;
            else if( freq[idx] != 3 ) freq[idx] = 2; 
        }
        vector<vector<int>> ans(2);
        for( int i = 0 ; i <= N ; i++ ){
            if( freq[i] == 1 ) ans[0].push_back(i-offset);
            if( freq[i] == 2 ) ans[1].push_back(i-offset);
        }
        return ans;
    }
};
