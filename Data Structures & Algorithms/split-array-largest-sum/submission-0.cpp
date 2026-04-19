class Solution {
private:
    vector<int> prefix;
    int rangesum(vector<int>& nums, int l, int r){
        return prefix[r] - prefix[l] + nums[l];
    }
    int f(vector<int>& nums, int k, int idx, vector<vector<int>> &dp){
        int n = nums.size();
        if(idx == n){
            if(k == 0){
                return 0;
            }
            else return INT_MAX;
        }
        if(k == 0) return INT_MAX;
        if(dp[idx][k] != -1) return dp[idx][k];
        int mini = INT_MAX;
        for(int i = idx; i < n; i++){
            mini = min(mini, max(f(nums, k-1, i+1, dp), rangesum(nums, idx, i)));
        }
        return dp[idx][k] = mini;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        prefix.resize(n, 0);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return f(nums, k, 0, dp);
    }
};