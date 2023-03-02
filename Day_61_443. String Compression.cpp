class Solution {
public:
    int compress(vector<char>& chars) {
        // ac ( 30 : 00 timer ) solve on ( 21 : 00 )
        int n = chars.size() , ans = 0 , i = 0 , k = 0 ; 
        while( i < n ){
            int len = 1 , j = i+1 ;
            char x = chars[i]; 
            while ( j < n && chars[j] == x ) j++ , len++ ;
            i = j ; 
            ans++;
            chars[k++] = x ; 
            if ( len == 1 ) continue; 
            string num = to_string(len); 
            for(auto &i : num){
                chars[k++] = i;
                ans++; 
            }
        }
        cout << ans << endl;
        return ans;
    }
};
