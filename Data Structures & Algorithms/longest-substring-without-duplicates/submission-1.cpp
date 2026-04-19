class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int l = 0;
        unordered_map<char, int> freq;
        int maxlen = 1;
        freq[s[0]]++;
        for(int r = 1; r < n; r++){
            if(freq[s[r]]){
                while(freq[s[r]]){
                    freq[s[l]]--;
                    l++;
                }
                freq[s[r]]++;
                maxlen = max(maxlen, r-l+1);
            }
            else {
                freq[s[r]]++;
                maxlen = max(maxlen, r-l+1);
            }
        }
        return maxlen;
    }
};
