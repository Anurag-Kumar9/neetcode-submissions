class Solution {
private:
    vector<string> getNeighbors(string node) {
    vector<string> neighbors;
    
    for (int i = 0; i < 4; i++) {
        string temp = node;
        temp[i] = (node[i] == '9') ? '0' : node[i] + 1;
        neighbors.push_back(temp);
        temp[i] = (node[i] == '0') ? '9' : node[i] - 1;
        neighbors.push_back(temp);
    }
    
    return neighbors;
}
public:
    int openLock(vector<string>& deadends, string target) {
        if(target == "0000") return 0;
        unordered_set<string> dead(deadends.begin(), deadends.end());

        if(dead.count("0000")) return -1;

        int level = 0;
        unordered_set<string> visited;
        visited.reserve(10000);
        queue<string> q;
        q.push("0000");
        visited.insert("0000");

        while(!q.empty()){
            int size = q.size();
            level++;
            while(size--){
                string front = q.front();
                q.pop();
                if(front == target) return level-1;
                vector<string> nei = getNeighbors(front);
                for(auto n : nei){
                    if(!(visited.count(n) || dead.count(n))){
                        q.push(n);
                        visited.insert(n);
                    }
                }
            }
        }
        return -1;
    }
};