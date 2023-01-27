class Solution {
public:
    map<string,bool> vis;
    vector<string> ans; 
  
    void rec( string & x , string part , int i , bool & valid ){
         
        if ( i >= x.size() ) { 
            if ( part == "" || ( vis[part] && part != x ) ) valid = true ; 
            return;
        }
        
        // case 1 :::::::  
        // append
        string nxt = part;
        nxt.push_back(x[i]);
        rec(x,nxt,i+1,valid);
        
        // case 2 :::::::
        // start new 
        // iff ( if and only if ) the prev actually a correct/valid to concatenate  
        if ( vis[part] ){
            string nxt = "";
            nxt.push_back(x[i]);
            rec(x,nxt,i+1,valid);
        }
        
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for( int i = 0 ; i < words.size() ; i++ ) vis[words[i]] = true ;
        for( int i = 0 ; i < words.size() ; i++ ){
            bool valid = false ; 
            rec(words[i],"",0,valid) ;
            if (valid) ans.push_back(words[i]) ;
        }
        return ans; 
    }
};
