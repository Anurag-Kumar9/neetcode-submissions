class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> count;
        for(int i = 0; i < n; i++){
            count[nums[i]]++;
        }

        for(auto &temp : count){
            if(temp.second > n/3)ans.push_back(temp.first);
        }

        return ans;
    }
};