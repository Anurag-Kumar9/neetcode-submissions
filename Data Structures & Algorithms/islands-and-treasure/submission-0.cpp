class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int curr = 0;
        while(!q.empty()){
            int size = q.size();
            curr++;

            for(int i = 0; i < size; i++){
                auto [r, c] = q.front();
                q.pop();

                int dx[] = {-1, 1, 0, 0};
                int dy[] = {0, 0, -1, 1};

                for(int x = 0; x < 4; x++){
                    int nx = r + dx[x];
                    int ny = c + dy[x];

                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny] || grid[nx][ny] == -1) continue;

                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    grid[nx][ny] = curr;
                }
            }
        }
    }
};
