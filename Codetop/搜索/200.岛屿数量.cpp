// 一刷：2022 03 17 不会做，不会写 DFS
// 二刷：2022 03 18 大概会做，会写 DFS，在细节的地方出 bug 了
// 三刷：2022 03 21 大概会做，会写 DFS 迭代和递归，在细节的地方出 bug 了
// 四刷：2022 03 29 会写 DFS 迭代和递归
// 五刷：2022 06 08 大概会写，上次诺亚面试写过...

// 非递归 DFS
// 时间复杂度 O(m * n)
// 空间复杂度 O(min(m,n))

class Solution {
public:
    vector<int> direction = {-1, 0, 1, 0, -1};
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        
        stack<pair<int, int>> S;
        for(int i = 0; i < m; ++i){
            for(int j = 0;j < n; ++j){
                if(grid[i][j] =='1'){
                    ++ans;
                    S.push({i,j});
                    // grid[i][j] = '0';
                    
                    while(!S.empty()){
                        auto [x, y] = S.top();
                        S.pop();
                        grid[x][y] = '0';
                        
                        for(int k = 0; k < 4; ++k){
                            int newx = x + direction[k];
                            int newy = y + direction[k + 1];
                            if(newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == '1'){
                                S.push({newx, newy});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};



// 递归DFS
// 时间复杂度 O(m * n)
// 空间复杂度 O(m * n)
class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    void dfs(vector<vector<char>>& grid, int x, int y){
        if(grid[x][y] == '1'){
            grid[x][y] = '0';
            for(int k = 0; k < 4; ++k){
                int newx = x + direction[k];
                int newy = y + direction[k + 1];
                if(newx >= 0 && newy >= 0 && newx < grid.size() && newy < grid[0].size())
                    dfs(grid, newx, newy);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;

        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    ans++;                    
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};