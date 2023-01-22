class Solution {
public:
    vector<vector<string>>ans;
    vector<string>path ; 

    bool isPal( string & x ){ 
        for ( int i = 0 ; i <= x.size() / 2 ; i++ ) {
            if ( x[i] != x[x.size()-i-1] ) return false ;
        }
        return true ; 
    }

    void bck( int i , string & s ){
        if( i >= s.size() ){
            if ( !path.empty() && isPal(path.back()) ) ans.push_back(path) ;
            return; 
        }
        
        // case 1 : append to the latest cell we have
        string x = "";
        x = x + s[i] ;
        if ( path.empty() ) path.push_back(x);
        else path.back() += x ;
        bck(i+1,s) ;
        path.back().pop_back();
        if ( path.back().empty() ) path.pop_back() ;

        // case 2 : create new cell in the path 
        if ( !path.empty() && isPal(path.back()) ) {
            path.push_back(x);
            bck(i+1,s);
            path.pop_back();
        }

    }

    vector<vector<string>> partition(string s) {
        bck(0,s);
        return ans ;
    }
};

// for ( auto i : ans ) {
//     for ( auto j : i ) {
//         cout << j << " " ; 
//     }
//     cout << endl ;
// }
