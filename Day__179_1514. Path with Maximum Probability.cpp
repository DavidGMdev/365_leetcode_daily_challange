class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double,int>>> adj(n);
        for (int i = 0 ; i < edges.size() ; i++ ) {
            adj[edges[i][0]].push_back({succProb[i] , edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i] , edges[i][0]});
        }
      // solve using dijkistra graph algorithm ( obtain max path prob rather than smallest )( longest path / more costy than shortest one )
        priority_queue<pair<double,int>> pq;
        vector<double>best_prob(n,0.0);
        pq.push({1.0,start});
         while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            if( curr.second == end ) return curr.first;
            for(auto & child : adj[curr.second]){
                if( curr.first*child.first > best_prob[child.second] ){ // maximize rather than minimize 
                    pq.push({curr.first*child.first,child.second});
                    best_prob[child.second] = curr.first*child.first;
                }
            }   
        }
        return best_prob[end]; // actually if here reached , it's just unreachable ( i.e Must be zero probablity , disconnected components )
    }
};
