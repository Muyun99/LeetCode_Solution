// DFS 递归写法
// 时间复杂度 O(m * n)
// 空间复杂度 O(m * n)

class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    int dfs(vector<vector<int>>& grid, int x, int y){
        if(grid[x][y] == 0)
            return 0;
        grid[x][y] = 0;
        
        int newx, newy, area = 1;

        for(int i = 0; i < 4; ++i){
            newx = x + direction[i];
            newy = y + direction[i + 1];
            
            if(newx < grid.size() && newy < grid[0].size() && newx >= 0 && newy >= 0)
                area += dfs(grid, newx, newy);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()){
            return 0;
        }
        
        int maxArea = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1)
                    maxArea = max(maxArea, dfs(grid, i, j));
            }
        return maxArea;
    }
};

// DFS 的非递归写法
// 时间复杂度 O(m * n)
// 空间复杂度 O(m * n)
class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();

        int local_area;
        int ans = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    local_area = 1;
                    grid[i][j] = 0;

                    stack<pair<int, int>> island;
                    island.push({i, j});
                    
                    while(!island.empty()){
                        auto [x, y] = island.top();
                        island.pop();

                        for(int k = 0; k < 4; ++k){
                            int newx = x + direction[k];
                            int newy = y + direction[k + 1];
                            
                            if(newx < m && newx >= 0 && newy < n && newy >= 0 && grid[newx][newy] == 1){
                                grid[newx][newy] = 0;
                                ++local_area;
                                island.push({newx, newy});
                            }
                        }
                    }
                    ans = max(ans, local_area);
                }
            }
        return ans;
    }
};

// BFS 的非递归写法
// 时间复杂度 O(m * n)
// 空间复杂度 O(m * n)
class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();

        int local_area;
        int ans = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    local_area = 1;
                    grid[i][j] = 0;

                    queue<pair<int, int>> island;
                    island.push({i, j});
                    
                    while(!island.empty()){
                        auto [x, y] = island.front();
                        island.pop();

                        for(int k = 0; k < 4; ++k){
                            int newx = x + direction[k];
                            int newy = y + direction[k + 1];
                            
                            if(newx < m && newx >= 0 && newy < n && newy >= 0 && grid[newx][newy] == 1){
                                grid[newx][newy] = 0;
                                ++local_area;
                                island.push({newx, newy});
                            }
                        }
                    }
                    ans = max(ans, local_area);
                }
            }
        return ans;
    }
};