class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        int ans = -1;
        while(!q.empty()){
            int x = q.size();
            ans++;
            for(int i = 0; i < x; i++){
                auto [r, c] = q.front();
                q.pop();

                int dx[] = {-1, 1, 0, 0};
                int dy[] = {0, 0, -1, 1};

                for(int i = 0; i < 4; i++){
                    int nx = r+dx[i];
                    int ny = c+dy[i];

                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] == 0 || visited[nx][ny]) continue;

                    q.push({nx, ny});
                    grid[nx][ny] = 2;
                    visited[nx][ny] = true;
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans >= 0 ? ans : 0;
    }
};