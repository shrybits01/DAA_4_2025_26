class Solution {
public:
    
    int find(int x, vector<int>& parent) {
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x], parent);
    }
    
    int kruskalsMST(int V, vector<vector<int>>& edges) {
        
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });
        
        vector<int> parent(V);
        for(int i = 0; i < V; i++)
            parent[i] = i;
        
        int sum = 0;
        int count = 0;
        
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            int pu = find(u, parent);
            int pv = find(v, parent);
            
            if(pu != pv) {
                parent[pu] = pv;
                sum += w;
                count++;
                
                if(count == V - 1)
                    break;
            }
        }
        
        return sum;
    }
};