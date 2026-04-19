class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maximum = 0;
        for(int num : st){
            if(!st.count(num-1)){
                int curr = 1;
                int currNum = num;
                while(st.count(currNum + 1)){
                    curr++;
                    currNum++;
                }
                maximum = max(maximum, curr);
            }
        }
        return maximum;
    }
};
