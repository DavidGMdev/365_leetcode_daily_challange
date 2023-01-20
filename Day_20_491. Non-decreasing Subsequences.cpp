class Solution {
public:
    vector<vector<int>> ans;
    vector<int> pick;
    void bck( int i , vector<int>& nums , vector<int>& pick ){ 
        if ( i >= nums.size() ){
            if(pick.size() > 1) ans.push_back(pick);
            return ;
        }
        if (  pick.empty() || nums[i] != pick.back() ) {
            bck(i+1,nums,pick);
        }
        if ( pick.empty() || nums[i] >= pick.back() ) {
            pick.push_back(nums[i]);
            bck(i+1,nums,pick);
            pick.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        bck(0,nums,pick);
        return ans; 
    }
};
