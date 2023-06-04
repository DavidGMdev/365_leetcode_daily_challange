class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected , vector<bool>& vis ){ 
        vis[node] = true;
        for( int child = 0 ; child < isConnected.size() ; child++ ){
            if( !isConnected[node][child] || vis[child] || node == child ) continue;
            dfs(child,isConnected,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // connected indirectly = have path exist 
        // in other terms => count strongly connected components 
        int ans = 0 ; 
        vector<bool>vis(isConnected.size(),false);
        for ( int i = 0 ; i < isConnected.size() ; i++ ){
            if(vis[i]) continue;
            dfs(i,isConnected,vis);
            ans++;
        }
        return ans;
    }
};
