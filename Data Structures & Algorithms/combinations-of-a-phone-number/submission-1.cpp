class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> hash(10);
        hash[2] = "abc";
        hash[3] = "def";
        hash[4] = "ghi";
        hash[5] = "jkl";
        hash[6] = "mno";
        hash[7] = "pqrs";
        hash[8] = "tuv";
        hash[9] = "wxyz";
        string curr;
        vector<string> res;
        f(digits, 0, curr, res, hash);
        return res;
    }
    void f(string digits, int i, string &curr, vector<string> &res, vector<string> &hash){
        if(i == digits.size()){
            if(!curr.empty()) {
                res.push_back(curr);
            }
            return;
        }

        for(auto c : hash[digits[i] - '0']){
            curr.push_back(c);
            f(digits, i+1, curr, res, hash);
            curr.pop_back();
        }
    }
};
