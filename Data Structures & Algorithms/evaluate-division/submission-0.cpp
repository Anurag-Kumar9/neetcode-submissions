class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        int count = 0;
        unordered_map<string, int> mapping;

        for(auto &e : equations){
            if(!mapping.count(e[0])){
                mapping[e[0]] = count;
                count++;
            }
            if(!mapping.count(e[1])){
                mapping[e[1]] = count;
                count++;
            }
        }
        vector<vector<double>> val(count, vector<double>(count, -1));

        for(int i = 0; i < n; i++){
            val[mapping[equations[i][0]]][mapping[equations[i][1]]] = values[i];
            val[mapping[equations[i][1]]][mapping[equations[i][0]]] = 1 / values[i];
        }

        for(int i = 0; i < count; i++){
            val[i][i] = 1;
        }

        for(int k = 0; k < count; k++){
            for(int i = 0; i < count; i++){
                for(int j = 0; j < count; j++){
                    if(val[i][k] != -1.0 && val[k][j] != -1.0 && val[i][j] == -1){
                        val[i][j] = val[i][k] * val[k][j];
                    }
                }
            }
        }

        vector<double> ans;

        for(auto &q : queries){
            if(!(mapping.count(q[0]) && mapping.count(q[1]))){
                ans.push_back(-1);
                continue;
            }
            ans.push_back(val[mapping[q[0]]][mapping[q[1]]]);
        }

        return ans;
    }
};