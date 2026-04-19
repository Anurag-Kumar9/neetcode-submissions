class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans(k, vector<int>(k, 0));
        vector<vector<int>> graph_row(k + 1);
        vector<vector<int>> graph_col(k + 1);
        vector<int> indegree_row(k + 1);
        vector<int> indegree_col(k + 1);
        vector<int> topo_row;
        vector<int> topo_col;
        queue<int> q_row;
        queue<int> q_col;
        unordered_map<int, int> row_pos;
        unordered_map<int, int> col_pos;

        for (auto& r : rowConditions) {
            graph_row[r[0]].push_back(r[1]);
            indegree_row[r[1]]++;
        }
        for (auto& c : colConditions) {
            graph_col[c[0]].push_back(c[1]);
            indegree_col[c[1]]++;
        }

        for (int i = 1; i <= k; i++) {
            if (indegree_row[i] == 0) {
                q_row.push(i);
            }
            if (indegree_col[i] == 0) {
                q_col.push(i);
            }
        }
        while (!q_row.empty()) {
            int front = q_row.front();
            q_row.pop();

            topo_row.push_back(front);
            for (auto nei : graph_row[front]) {
                indegree_row[nei]--;
                if (indegree_row[nei] == 0) {
                    q_row.push(nei);
                }
            }
        }
        if (topo_row.size() != k)
            return {};

        while (!q_col.empty()) {
            int front = q_col.front();
            q_col.pop();

            topo_col.push_back(front);
            for (auto nei : graph_col[front]) {
                indegree_col[nei]--;
                if (indegree_col[nei] == 0) {
                    q_col.push(nei);
                }
            }
        }
        if (topo_col.size() != k)
            return {};

        for (int i = 0; i < k; i++) {
            row_pos[topo_row[i]] = i;
            col_pos[topo_col[i]] = i;
        }

        for (int i = 1; i <= k; i++) {
            ans[row_pos[i]][col_pos[i]] = i;
        }

        return ans;
    }
};