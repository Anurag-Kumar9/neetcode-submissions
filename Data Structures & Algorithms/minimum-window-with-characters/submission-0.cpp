class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        unordered_map<char, int> hash;
        unordered_map<char, int> hash2;
        for(int i = 0; i < n; i++){
            hash[t[i]]++;
        }
        int min_len = INT_MAX;
        int start_pos = -1;
        int l = 0;
        for(int r = 0; r < m; r++){
            hash2[s[r]]++;
            bool found = 1;
            for(auto h : hash){
                if(hash2[h.first] < h.second){
                    found = 0;
                    break;
                }
            }
           while(found && l <= r){
                if(r-l+1 < min_len){
                    min_len = r-l+1;
                    start_pos = l;
                }
                hash2[s[l]]--;
                if(hash.count(s[l]) && hash2[s[l]] < hash[s[l]]){
                    found = false;
                }
                l++;
            }
        }
        if(start_pos == -1) return "";
        return s.substr(start_pos, min_len);
    }
};