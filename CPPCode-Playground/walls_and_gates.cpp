// https://leetcode.com/problems/walls-and-gates/

#include <queue>

class Solution {
public:
    struct Node {
        int step;
        int x;
        int y;
    };
    int x_[4] = {0, -1, 0, 1};
    int y_[4] = {1, 0, -1, 0};

    bool walkable(int x, int y, vector<vector<int>>& rooms) {
        return rooms[x][y] == 2147483647;
    }

    bool valid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if (m == 0) return;
        int n = rooms.front().size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<Node> queue;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) {
                    visited[i][j] = true;
                    queue.push({0, i, j});
                }
            }
        }

        while(!queue.empty()) {
            Node node = queue.front(); queue.pop();
            int x = node.x;
            int y = node.y;
            int step = node.step;
            for(int i = 0; i < 4; ++i) {
                int s_x = x + x_[i];
                int s_y = y + y_[i];
                if (valid(s_x, s_y, m, n) && walkable(s_x, s_y, rooms) && !visited[s_x][s_y]) {
                    // valid position and not visited;
                    visited[s_x][s_y] = true; // set its visited
                    rooms[s_x][s_y] = step + 1;
                    queue.push({
                        step + 1,
                        s_x,
                        s_y
                    });
                }
            }
        }

    }
};
