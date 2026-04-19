class Solution {
private:
    bool isPal(string &s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            else {
                l++;
                r--;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string &s) {
        int l = 0;
        int r = s.size() - 1;
        while(l < r){
            if(s[l] != s[r]){
                return isPal(s, l+1, r) || isPal(s, l, r-1);
            }
            else {
                l++;
                r--;
            }
        }
    }
};