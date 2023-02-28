class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for ( int i = 0 ; i < nums.size() ; i++ ){
            s.insert(nums[i]%2? nums[i]*2 : nums[i]);
        }
       // also can use priority queue rather than set 
        int res = *s.rbegin() - *s.begin(); // max - min 
        while (*s.rbegin()%2==0) { // max is even 
            s.insert(*s.rbegin()/2);  // divide max by 2 
            s.erase(*s.rbegin()); 
            res = min(res, *s.rbegin() - *s.begin()); // max - min max deviation
        }
        return res;
    }
};
