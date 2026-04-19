class Solution {
private:
    bool dfs(vector<vector<char>> &board, string &word, int row, int col, int w, vector<vector<bool>> &visited){
        if(w == word.size() - 1)return true;
        visited[row][col] = 1;
        int m = board.size();
        int n = board[0].size();
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        for(int i = 0; i < 4; i++){
            int nr = row + dx[i];
            int nc = col + dy[i];
            if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            if(visited[nr][nc] || board[nr][nc] != word[w+1]) continue;
            if(dfs(board, word, nr, nc, w+1, visited)) return true;
        }
        visited[row][col] = 0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(word[0] == board[i][j]){
                    if(dfs(board, word, i, j, 0, visited)) return true;
                }
            }
        }
        return false;
    }
};