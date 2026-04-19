using T = tuple<int, int, int>;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);

        for(auto &f : flights){
            graph[f[0]].push_back({f[1], f[2]});
        }

        // Track minimum cost to reach each node with at most s stops
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;
        
        priority_queue<T, vector<T>, greater<>> pq;
        pq.push({0, src, 0});
        
        while(!pq.empty()){
            auto [d, x, s] = pq.top();
            pq.pop();

            if(s > k || d > dist[x][s]) continue;

            for(auto [nei, pri] : graph[x]){
                int newStops = s + 1;
                int newCost = d + pri;
                if(newStops <= k + 1 && dist[nei][newStops] > newCost){
                    dist[nei][newStops] = newCost;
                    pq.push({newCost, nei, newStops});
                }
            }
        }
        
        int ans = INT_MAX;
        for(int i = 0; i <= k + 1; i++){
            ans = min(ans, dist[dst][i]);
        }
        return (ans != INT_MAX) ? ans : -1;
    }
};