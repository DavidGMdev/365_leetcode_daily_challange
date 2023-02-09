class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string,bool> mp;
        long long ans = 0 ; 
        int n = ideas.size() , go[26][26] = {0};  
        for(auto &i :ideas ) mp[i] = true;
        for( int i = 0 ; i < n ; i++ ){
            int from = ideas[i][0] - 'a'; 
            for( int to = 0 ; to < 26 ; to++ ){
                if(to == from) continue;
                ideas[i][0] = to + 'a' ;
                if(mp.find(ideas[i]) == mp.end()) {
                    ans += (2*go[to][from]);
                    go[from][to]++;
                }
            }
        }
        return ans ; 
    }
};
/*
    interesting behaviour : on specific LARGE testcases  
    unordered map
        !mp[y] => 1607 local ,TLE on submission 
        mp.find(y) == mp.end() => 217ms local , AC on submission
    map 
        !mp[y] => TLE local , TLE on submission
        mp.find(y) == mp.end() => 1243ms local , TLE on submission

*/
