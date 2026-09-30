//bfs 用Queue解决
class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));    
        vector<vector<int>> res;

        queue<pair<int, int>> pacQueue, atlQueue;

        for(int r = 0; r < ROWS; r ++) {
            pacQueue.push({r, 0});
            atlQueue.push({r, COLS - 1});
        }
        for(int c = 0; c < COLS; c ++) {
            pacQueue.push({0, c});
            atlQueue.push({ROWS - 1, c});
        }

        bfs(pacQueue, pac, heights);
        bfs(atlQueue, atl, heights);

        for(int r = 0; r < ROWS; r ++) {
            for(int c = 0; c < COLS; c ++) {
                if(pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        return res;

    }

    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        while(!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            ocean[r][c] = true;
            for(auto [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if(nr >= 0 && nc >= 0 && nr < heights.size() && nc < heights[0].size() && ocean[nr][nc] == false && heights[nr][nc] >= heights[r][c]) {
                    q.push({nr, nc});
                }
            }
        }
    }
};
