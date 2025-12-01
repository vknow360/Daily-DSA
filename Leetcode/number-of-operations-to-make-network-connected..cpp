class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (y_parent == x_parent)
            return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int e = connections.size();
        if (n > e + 1)
            return -1;

        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto& vec : connections) {
            int x = vec[0], y = vec[1];
            if (find(x) != find(y)) {
                Union(x, y);
            }
        }
        int components = 0;
        for (int i = 0; i < n; i++)
            if (find(i) == i)
                components++;
        return components - 1;
    }
};