class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        vector<string> st;
        for(int i = 0; i < n; i++){
            if(path[i] == '/') continue;
            string temp = "";
            while(i < n && path[i] != '/'){
                temp += path[i];
                i++;
            }
            if(temp == ".") continue;
            else if(temp == "..") {
                if(!st.empty()) st.pop_back();
            }
            else st.push_back(temp);
        }
        string ans = "/";
        for(int i = 0; i < st.size(); i++){
            ans += st[i];
            if(i != st.size()-1) ans += '/';
        }
        return ans;
    }
};