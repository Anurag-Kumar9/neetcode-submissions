class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        //remove irrelevent
        for(int i = 0; i < n; i++){
            if(nums[i] > 0 && nums[i] <= n)continue;
            nums[i] = n+1;
        }
        //mark indices
        for(int i = 0; i < n; i++){
            if(nums[i] == n+1 || nums[i] == -n-1) continue;
            if(nums[abs(nums[i]) - 1] > 0){
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            }
        }
        //check which doesn't exist
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) return i+1;
        }
        return n+1;
    }
};