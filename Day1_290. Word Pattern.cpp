class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string,string> mp;
        int n = s.size();
        string x ;
        vector<string>v;
        for(int i = 0 ; i < n ; i++ ){
            if ( s[i] != ' ' ) x += s[i] ; 
            else {
                v.push_back(x);
                x = "";
            }
        }
        if(x!="") v.push_back(x);
        n = pattern.size();
        int m = v.size();
        if( n!=m ) return false ;
        for( int i = 0 ; i < n ; i++ ){
            if(mp[to_string(pattern[i])] == "" && mp[v[i]] == "" ) {
                mp[to_string(pattern[i])] = v[i] ;
                mp[ v[i] ] = to_string(pattern[i]) ;
            }
            else if ( mp[to_string(pattern[i])] != v[i] || mp[v[i]] != to_string(pattern[i])  ) {
                return false ;
            }
        }
        return true ;
    }
};
