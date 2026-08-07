class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue < pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> pq;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while (!pq.empty()) {
            int curr_cost = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if (x == n - 1 && y == m - 1)
                return curr_cost;
            if (curr_cost > dist[x][y])
                continue;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int jump_cost = grid[nx][ny];
                    int new_cost = curr_cost + jump_cost;
                    if (dist[nx][ny] > new_cost) {
                        dist[nx][ny] = new_cost;
                        pq.push({new_cost, {nx, ny}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};