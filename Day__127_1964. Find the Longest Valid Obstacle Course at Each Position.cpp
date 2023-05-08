// New concept : lowest increasing subsequance perserve
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> LIS; // lowest increasing subsequance
        int n = obstacles.size(); 
        vector<int> ans(n,1);
        for( int i = 0 ; i < n ; i++ ){
            int j = upper_bound(LIS.begin(),LIS.end(),obstacles[i]) - LIS.begin() ;
            if( j == LIS.size() ) {
                LIS.push_back(obstacles[i]);
            }
            else {
                LIS[j] = obstacles[i]; // nice point 
            }
            ans[i] += j;
        }
        return ans;
    }
};
