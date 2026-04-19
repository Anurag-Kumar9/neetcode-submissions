class Solution {
private:
    bool isPal(string &s, int l, int r){
        while(l < r) {
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void f(string &s, int start, vector<string> &curr, vector<vector<string>> &res){
        if(start == s.size()){
            res.push_back(curr);
            return;
        }

        for(int i = start; i < s.size(); i++){
            if(isPal(s, start, i)){
                curr.push_back(s.substr(start, i-start+1));
                f(s, i+1, curr, res);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> res;
        f(s, 0, curr, res);
        return res;
    }
};
