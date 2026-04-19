class Solution {
public:
    int numSquares(int n) {
        int st = (int) sqrt(n);
        vector<int> ps(st);
        for(int i = 1; i <= st; i++){
            ps[i-1] = i*i;
        }
        vector<vector<int>> dp(n+1, vector<int>(st, 0));
        for(int j = 1; j <= n; j++){
            if(j % ps[st-1] == 0) dp[j][st-1] = j/ps[st-1];
            else {
                dp[j][st-1] = 1e9;
            }
        }
        for(int j = 1; j <= n; j++){
            for(int i = st-2; i >= 0; i--){
                int notpick = dp[j][i+1];
                int pick = 1e9;
                if(j >= ps[i]){
                    pick = dp[j-ps[i]][i] + 1;
                }

                dp[j][i] = min(notpick, pick);
            }
        }
        return dp[n][0];
    }
};