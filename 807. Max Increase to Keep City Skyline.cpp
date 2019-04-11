class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> a, b;
        for(int i = 0; i < grid.size(); i++) {
            int maxx = -1;
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] > maxx)
                    maxx = grid[i][j];
            }
            a.push_back(maxx);
        }
        for(int i = 0; i < grid[0].size(); i++) {
            int maxx = -1;
            for(int j = 0; j < grid.size(); j++) {
                if(grid[j][i] > maxx)
                    maxx = grid[j][i];
            }
            b.push_back(maxx);
        }
        // for(int i = 0; i < a.size(); i++) cout << a[i] << ' '; cout << endl;
        // for(int i = 0; i < b.size(); i++) cout << b[i] << ' '; cout << endl;
        int sum = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                sum += min(a[i], b[j])-grid[i][j];
            }
        }
        return sum;
    }
};