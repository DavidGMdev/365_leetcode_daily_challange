class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = -1; 
        for(auto & i : candies) mx = max(mx,i);
        vector<bool>ans(candies.size());
        for( int i = 0 ; i < ans.size() ; i++ ){
            ans[i] = ( candies[i] + extraCandies >= mx ) ;
        }
        return ans ;
    }
};
