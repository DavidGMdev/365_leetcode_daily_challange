class Solution {
public:
    void bfs(vector<int>&nums , vector<int>&dist ){
        queue<int>q ; // queue of indexes not values 
        q.push(0) ;
        dist[0] = 0 ; 
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for( int i = curr + 1 ;  i < nums.size() && i <= curr + nums[curr] ; i++ ){
                if ( dist[i] == -1 ) {
                    q.push(i);
                    dist[i] = dist[curr] + 1;
                }
            }
        }
        return; 
    }
    int jump(vector<int>& nums){
        int n = (int)nums.size();
        vector<int>dist(n,-1);
        bfs(nums,dist);
        return dist[n-1];
    }
};
