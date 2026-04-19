class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int closest_ind = 0;
        int n = arr.size();
        if(n == k) return arr;
        for(int i = 0; i < n; i++){
            if(abs(arr[i] - x) < abs(arr[closest_ind] - x)){
                closest_ind = i;
            }
        }
        int l = closest_ind;
        int r = closest_ind;
        while(r-l+1 != k){
            int temp_left = INT_MAX;
            int temp_right = INT_MAX;
            if(l > 0){
                temp_left = abs(arr[l-1] - x);
            }
            if(r < n-1){
                temp_right = abs(arr[r+1] - x);
            }

            if(temp_left <= temp_right){
                l--;
            }
            else {
                r++;
            }

        }
        return vector<int>(arr.begin() + l, arr.begin() + r+1);
    }
};