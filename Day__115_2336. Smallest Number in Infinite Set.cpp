class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>>q;
    bool q_vis[1001] = {0};
    int curr = 1; 
    SmallestInfiniteSet() {}
    int popSmallest() {
        if( q.empty() || curr < q.top() ){
            return curr++;
        }
        else{
            int trg = q.top();
            q.pop();
            q_vis[trg] = false;
            return trg;
        }
    }
    void addBack(int num) {
        if ( num >= curr || q_vis[num] ) return;
        q_vis[num] = true;
        q.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
