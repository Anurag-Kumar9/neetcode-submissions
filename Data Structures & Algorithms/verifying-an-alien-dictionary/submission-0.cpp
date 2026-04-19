class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        unordered_map<char, int> o;
        for(int i = 0; i < 26; i++){
            o[order[i]] = i;
        }

        for(int i = 1; i < n; i++){
            string temp1 = words[i-1];
            string temp2 = words[i];

            int x = min(temp1.size(), temp2.size());
            int good = 0;
            for(int j = 0; j < x; j++){
                if(temp1[j] == temp2[j]) continue;
                else if(o[temp1[j]] < o[temp2[j]]){
                    good = 1;
                    break;
                }
                else {
                    return false;
                }
            }
            if(!good && temp2.size() < temp1.size()){
                return false;
            }
        }
        return true;
    }
};