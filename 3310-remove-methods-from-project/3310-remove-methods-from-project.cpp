class Solution {
public:
    vector<vector<int>> g, adj;
    vector<bool> suspicious, vis;

    void dfs1(int u) {
        suspicious[u] = true;

        for (int v : g[u]) {
            if (!suspicious[v])
                dfs1(v);
        }
    }

    void dfs2(int u) {
        vis[u] = true;

        for (int v : adj[u]) {
            if (!vis[v]) {
                suspicious[v] = false;
                dfs2(v);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        g.assign(n, {});
        adj.assign(n, {});
        suspicious.assign(n, false);
        vis.assign(n, false);

        for (auto &e : invocations) {
            int a = e[0];
            int b = e[1];

            g[a].push_back(b);

            // Undirected graph
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // Mark suspicious methods
        dfs1(k);

        // Explore from every non-suspicious node
        for (int i = 0; i < n; i++) {
            if (!suspicious[i] && !vis[i]) {
                dfs2(i);
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};