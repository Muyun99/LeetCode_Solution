// 非递归 DFS
// 时间复杂度 O(m * n)
// 空间复杂度 O(min(m,n))

class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;

        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    ++ans;
                    grid[i][j] = '0';

                    stack<pair<int, int>> island;
                    island.push({i, j});
                    
                    while(!island.empty()){
                        auto [x, y] = island.top();
                        island.pop();
                        
                        for(int k = 0; k < 4; ++k){
                            int newx = x + direction[k];
                            int newy = y + direction[k + 1];
                            if(newx >= 0 && newy >= 0 && newx < m && newy < n && grid[newx][newy] == '1'){
                                grid[newx][newy] = '0';
                                island.push({newx, newy});
                            }
                        }
                    }
                    
                }

            }
        }
        return ans;
        
    }
};

// 并查集