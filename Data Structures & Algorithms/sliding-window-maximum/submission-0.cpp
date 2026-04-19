class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n <= k){
            return {*max_element(nums.begin(), nums.end())};
        }
        deque<int> dq;
        for(int i = 0; i < k; i++){
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        vector<int> ans;
        ans.push_back(nums[dq.front()]);
        if(dq.front() == 0) dq.pop_front();
        for(int r = k; r < n; r++){
            while(!dq.empty() && nums[dq.back()] < nums[r]) dq.pop_back();
            dq.push_back(r);
            ans.push_back(nums[dq.front()]);
            if(dq.front() == r-k+1){
                dq.pop_front();
            }
        }
        return ans;
    }
};