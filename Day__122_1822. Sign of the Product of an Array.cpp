class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        int n = salary.size();
        double ans = 0 ;
        for(int i = 1 ; i < n-1 ; i++ ) ans += salary[i];
        ans/= ( n*1.0 - 2.0 );
        return ans;
    }
};
