class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        for(int r = 0; r < m; r++){
            if(board[r][0] == 'O'){
                q.push({r, 0});
                visited[r][0] = true;
            }
            if(board[r][n-1] == 'O'){
                q.push({r, n-1});
                visited[r][n-1] = true;
            }
        }

        for(int c = 0; c < n; c++){
            if(board[0][c] == 'O'){
                q.push({0, c});
                visited[0][c] = true;
            }
            if(board[m-1][c] == 'O'){
                q.push({m-1, c});
                visited[m-1][c] = true;
            }
        }

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            for(int i = 0; i < 4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr < 0 || nc < 0 || nr >= m || nc >= n || visited[nr][nc] || board[nr][nc] == 'X') continue;
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
