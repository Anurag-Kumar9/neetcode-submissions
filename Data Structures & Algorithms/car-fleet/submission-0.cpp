class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> combine;
        int n = position.size();
        for(int i = 0; i < n; i++){
            combine.push_back({position[i], speed[i]});
        }
        sort(combine.begin(), combine.end());
        stack<pair<int, int>> st;
        for(int i = n-1; i >= 0; i--){
            if(st.empty()) st.push(combine[i]);
            if(!st.empty() && ((float)(target-st.top().first)/st.top().second) < ((float)(target-combine[i].first)/combine[i].second)){
                st.push(combine[i]);
            }
        }
        return st.size();
    }
};