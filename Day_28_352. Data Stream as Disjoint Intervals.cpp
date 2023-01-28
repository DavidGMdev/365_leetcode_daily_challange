class SummaryRanges {
public:
    set<vector<int>> intervals; // [ [x,y] , [x,y] , ...etc ]
    SummaryRanges() {}
    bool canMerge(vector<int>  a , vector<int> b ){
        return ( a[0] <= b[0] && b[0] <= a[1] + 1 )  ; 
    }
    vector<int> merge( vector<int> a , vector<int> b ){
        return {min(a[0],b[0]),max(a[1],b[1])};
    }
    void addNum(int value) {
        intervals.insert({value,value});
    }
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        set<vector<int>> spare;
        // fetch 
        vector<int> curr = {} ;
        for( auto & i : intervals ){
            if ( curr.empty() ) curr = i ; 
            else {
                if( canMerge(curr,i) ) curr = merge(curr,i);
                else {
                    ans.push_back(curr);
                    spare.insert(curr);
                    curr = i;
                }
            }
        }
        ans.push_back(curr);
        spare.insert(curr);

        // reuse
        intervals = spare ;
        return ans ; 
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
