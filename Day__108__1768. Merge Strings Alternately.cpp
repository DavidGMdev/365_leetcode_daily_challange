class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int n = word1.size(), m = word2.size() ;
        int i = 0 , j = 0 ;
        bool flg = 0;
        string ans = "";
        while( i < n || j < m ){
            if( j >= m ){
                ans+= word1[i++];
            }
            else if ( i >= n ){
                ans+= word2[j++];
            }
            else if (flg){
                ans+= word2[j++];
            }
            else {
                ans+= word1[i++];
            }
            flg^=1;
        }
        return ans;
    }
};
