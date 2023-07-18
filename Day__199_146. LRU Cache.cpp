class LRUCache {
public:
    static const int N = 1e4;
    int cache[N+1];
    int capacity = 0 ;
    int curr = 0 ;

    vector<int>calls;
    unordered_map<int,int>lst;
    int lptr = 0 , rptr = -1;

    LRUCache(int capacity) {
        memset(cache,-1,sizeof(cache));
        this->capacity = capacity ;
    }
    void update(int key){
        calls.push_back(key);
        rptr++;
        if( lst.find(key) != lst.end() ){
            int index = lst[key];
            calls[index] = -1 ;
        }
        lst[key] = rptr;
    }
    int get(int key) {
        if( cache[key] != -1 ) update(key);  // should we constraint it ?
        return cache[key];
    }
    void put(int key, int value) {
        if( cache[key] == -1 && ++curr > capacity ){
            while(calls[lptr] == -1) lptr++;
            int lru = calls[lptr++];
            cache[lru] = -1;
        }
        update(key);
        cache[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
