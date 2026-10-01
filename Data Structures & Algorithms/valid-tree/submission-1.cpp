class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) {
            return false;
        }
        vector<vector<int>> adj(n);
        unordered_set<int> visit;
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        if(!dfs(0, -1, adj, visit)) {
            return false;
        }
        
        return visit.size() == n;
    }

    bool dfs(int node, int parent, vector<vector<int>>& adj, unordered_set<int>& visit) {
        if(visit.count(node)) {
            return false;
        }
        visit.insert(node);
        for(int nei : adj[node]) {
            if(nei == parent) {
                continue;
            }
            if(!dfs(nei, node, adj, visit)) {
                return false;
            }
        }
        return true;
    }
};
