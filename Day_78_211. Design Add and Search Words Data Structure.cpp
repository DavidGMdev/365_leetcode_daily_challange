
// ############################################################
// solution 1 : brute force , make use of 1e4 max calls 
// ( worst case will be < 1e7 ) , then fit  
// ############################################################

class WordDictionary {
public:
    vector<string> v; 
    WordDictionary() {}
  
    void addWord(string word) {
        v.emplace_back(word);     
    }
    
    bool search(string word) {
        for(auto & i : v){
            if( i.size() != word.size() ) continue ;
            bool flg = true ;
            for ( int j = 0 ; j < word.size() ; j++ ){
                if ( i[j] != word[j] && word[j] != '.' ){
                    flg = false ;
                    break;
                }
            }
            if (flg) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
