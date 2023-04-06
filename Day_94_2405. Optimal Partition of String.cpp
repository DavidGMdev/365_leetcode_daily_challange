class Solution {
public:
    int partitionString(string s) {
        int n = s.size() , ans = 1; 
        bool vis[26] = {0};
        for( int i = 0 ; i < n ; i++ ){
            if( vis[s[i] -'a'] ){
                ans++;
                for( int j = 0 ; j < 26 ; j++ ) vis[j] = false; 
            }
            vis[s[i] -'a'] = true;
        }
        return ans;
    }
};
