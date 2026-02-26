class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[V];
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});   
        }
                priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;
        vector<int> visited(V, 0);
        pq.push({0, 0});
        int sum = 0;
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;
            if(visited[node]) continue;
            visited[node] = 1;
            sum += wt;
            for(auto &it : adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;
                if(!visited[adjNode]) {
                    pq.push({edgeWt, adjNode});
                }
            }
        }
        return sum;
    }
};