class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool found[3] = {false};
        for(const auto &t : triplets){
            if(t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) continue;
            if(t[0] == target[0]) found[0] = true;
            if(t[1] == target[1]) found[1] = true;
            if(t[2] == target[2]) found[2] = true;
            if(found[0] && found[1] && found[2]) return true;
        }
        return found[0] && found[1] && found[2];
    }
};