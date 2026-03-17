class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        int drow[] = {0, -1, 0, 1};
        int dcol[] = {1, 0, -1, 0};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }

        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;
            for (int i = 0; i < size; i++) {

                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = r + drow[i];
                    int nc = c + dcol[i];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        !vis[nr][nc] && grid[nr][nc] == 1) {
                        q.push({nr, nc});
                        grid[nr][nc] = 2;
                        vis[nr][nc] = 1;
                        rotted = true;
                    }
                }
            }
            if(rotted) ans++;
        }
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};