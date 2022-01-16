class Solution {
public:
    
    int m, n;
    
    bool isValid(int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        int cnt = 0;
        queue<pair<int, int> > q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    cnt++;
                }
            }
        }
        int temp = cnt;
        // cout << temp << endl;
        cnt = 0;
        while (!q.empty()) {
            auto p = q.front();
            int i = p.first, j = p.second;
            q.pop();
            
            if (isValid(i - 1, j) && grid[i - 1][j] == 1) {
                q.push({i - 1, j});
                cnt++;
                grid[i - 1][j] = 2;
            }
            if (isValid(i + 1, j) && grid[i + 1][j] == 1) {
                q.push({i + 1, j});
                cnt++;
                grid[i + 1][j] = 2;
            }
            if (isValid(i, j - 1) && grid[i][j - 1] == 1) {
                q.push({i, j - 1});
                cnt++;
                grid[i][j - 1] = 2;
            }
            if (isValid(i, j + 1) && grid[i][j + 1] == 1) {
                q.push({i, j + 1});
                cnt++;
                grid[i][j + 1] = 2;
            }
            if (--temp == 0) {
                ans++;
                temp = cnt;
                // cout << temp << endl;
                cnt = 0;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return (ans == 0 ? 0 : ans - 1);
    }
};
