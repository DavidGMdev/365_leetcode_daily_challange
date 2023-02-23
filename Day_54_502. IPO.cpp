bool cmp ( vector<int>& a , vector<int>& b ){
    if ( a[0] < b[0] ) return 1 ;
    else if ( b[0] < a[0] ) return 0 ; 
    else if ( b[1] < a[1] ) return 1 ;
    return 0 ;
}
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>> v ; 
        int n  = profits.size();
        for ( int i = 0 ; i < n ; i++ ) v.push_back({capital[i],profits[i]}) ; 
        sort(v.begin(),v.end(),cmp);
        long long have = w ;
        int i = 0 ; 
        priority_queue<int> pq;
        while(k--){
            // fetch
            while( i < n && v[i][0] <= have ){
                pq.push(v[i][1]);
                i++;
            }
            // pull 
            if(!pq.empty()){
                have += pq.top();
                pq.pop();
            }
        }
        return have; 
    }
};
