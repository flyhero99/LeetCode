class Solution {
public:
    struct node {
        int i, j, v;
        node() {}
        node(int i, int j, int v) : i(i), j(j), v(v) {}
    };
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = 0;
        if(n) m = matrix[0].size();
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        typedef pair<int, int> pii;
        int inf = 0x3f3f3f3f;
        queue<pii> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) q.push(make_pair(i, j));
                else matrix[i][j] = inf;
            }
        }
        while(!q.empty()) {
            pii t = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    int x = t.first+dx[i], y = t.second+dy[i];
                    if(0<=x&&x<n&&0<=y&&y<m&&matrix[x][y]>matrix[t.first][t.second]+1) {
                        matrix[x][y] = matrix[t.first][t.second]+1;
                        q.push(make_pair(x, y));
                    }
                    
                }
            }
        }
        return matrix;
    }
};