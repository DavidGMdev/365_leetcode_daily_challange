class Solution {
public:
    unordered_map<int,vector<int>>mp;
    int bfs( int src , vector<int>& arr ){
        int n = arr.size();
        queue<int> q ; 
        q.push(src);
        vector<int> dis(n,INT_MAX-1);
        dis[src] = 0 ;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            // 3 possible ways 

            // back 
            if ( curr+1 < n && dis[curr] + 1 < dis[curr+1]  ) {
                q.push( curr+1 ) ; 
                dis[curr+1]  = dis[curr] + 1 ; 
            }
            // go 
            if ( curr-1 > -1 && dis[curr] + 1 < dis[curr-1]  ){
                q.push( curr-1 ) ; 
                 dis[curr-1]  = dis[curr] + 1 ;
            }
            // TLE ?
            for(auto &i : mp[arr[curr]]){
                if ( dis[curr] + 1 < dis[i]   ){
                    q.push(i) ; 
                    dis[i] = dis[curr]+1; 
                }
            }
            mp[arr[curr]].clear(); // magic step of NO TLE

        }
        
        return dis[n-1];
    }
    int minJumps(vector<int>& arr) {
        for( int i = 0 ; i < arr.size() ; i++ ){
            mp[ arr[i] ].push_back(i);
        }
        return bfs(0,arr);
    }
};
