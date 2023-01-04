class Solution {
public:
    bool detectCapitalUse(string word) {
        int a = 0 , b = 0 ;
        if(isupper(word[0])) a++;
        for( int i = 1 ; i < word.size() ; i++ ) if ( isupper(word[i]) ) b++;
        return ( (a && ( !b || b == word.size()-1 ) )  || ( !a && !b) ) ;
        // case 1 : a && !b first upper and all other lower 
        // case 2 : a && b == n-1 upper and all other upper 
        // case 3 : !a && !b , no uppers 
    }
};
