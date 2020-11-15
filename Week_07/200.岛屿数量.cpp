/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        int nr = grid.size();
        int nc = grid[0].size();
        grid[row][col] = 0;
        if(row -1>=0 && grid[row -1][col] == '1') dfs(grid, row -1, col);
        if(row +1<nr && grid[row +1][col] == '1') dfs(grid, row +1, col);
        if(col -1>=0 && grid[row][col -1] == '1') dfs(grid, row, col -1);
        if(col +1<nc && grid[row][col +1] == '1') dfs(grid, row, col +1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();
        if(nr ==0 || nc == 0) return 0;
        int res =0;
        for(int i =0; i< nr; i++) {
            for(int j = 0; j <nc; j++) {
                if(grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};
// @lc code=end

