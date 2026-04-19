class Solution {
private:
    int f(vector<int>& coins, int remamount, int i, vector<vector<int>> &dp){
        if(i == coins.size())return 0;
        if(remamount == 0){
            return 1;
        }
        if(dp[i][remamount] != -1) return dp[i][remamount];
        int notpick = f(coins, remamount, i+1, dp);
        int pick = 0;
        if(remamount >= coins[i]){
            pick = f(coins, remamount-coins[i], i, dp);
        }
        return dp[i][remamount] = pick+notpick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return f(coins, amount, 0, dp);
    }
};
