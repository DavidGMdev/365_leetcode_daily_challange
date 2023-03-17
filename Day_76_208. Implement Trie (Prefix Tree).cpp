class Trie {
public:
    class Node {
        public :
            bool end = false ;
            Node* to[26] ;
    };

    Node * trie = new Node();
    
    Trie() {}
    void insert(string word) {
        auto curr = trie ;
        for ( int i = 0 ; i < word.size() ; i++ ){
            int j = word[i] - 'a';
            if( curr->to[j] == NULL ) curr->to[j] = new Node();
            curr = curr->to[j];
            if( i == word.size() - 1 ) {
                curr -> end = true ;
            }
        }
    }
    
    bool search(string word) {
        auto curr = trie ;
        for ( int i = 0 ; i < word.size() ; i++ ){
            int j = word[i] - 'a';
            curr = curr->to[j];
            if( curr == NULL ) return false ;
        }
        return (curr->end == true) ;
    }
    
    bool startsWith(string prefix) {
        auto curr = trie ;
        for ( int i = 0 ; i < prefix.size() ; i++ ){
            int j = prefix[i] - 'a';
            curr = curr->to[j];
            if( curr == NULL ) return false ;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
