using T = tuple<int, int, int>;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<T, vector<T>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        vector<vector<int>> elev(m, vector<int>(n, INT_MAX));

        elev[0][0] = grid[0][0];

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!pq.empty()){
            auto [maxi, r, c] = pq.top();
            pq.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;

                if(elev[nr][nc] > max(grid[nr][nc], maxi)){
                    elev[nr][nc] = max(grid[nr][nc], maxi);
                    pq.push({elev[nr][nc], nr, nc});
                }
            }
        }
        return elev[m-1][n-1];
    }
};