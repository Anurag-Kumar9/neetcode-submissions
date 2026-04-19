class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            while(!(st.empty()) && st.top().first < temperatures[i]){
                pair<int, int> top = st.top();
                st.pop();
                ans[top.second] = i-top.second;
            }
            st.push({temperatures[i], i});
        }
        return ans;
    }
};