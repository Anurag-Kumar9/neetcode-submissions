class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 1){
            return s == "0" ? 0 : 1;
        }
        vector<int> dp(n+1, 1);
        if(s[n-1] == '0'){
            dp[n-1] = 0;
        }

        for(int i = n-2; i >= 0; i--){
            if(s[i] == '0'){
                dp[i] = 0;
                continue;
            }
            dp[i] = dp[i+1];
            if(i+1 <= n-1 && stoi(s.substr(i, 2)) <= 26){
                dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};