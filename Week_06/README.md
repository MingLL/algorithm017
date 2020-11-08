# 学习笔记
## 动态规划
&emsp;&emsp;动态规划比较适合用来解决最优问题，比如求最大值，最小值等等，它可以非常显著的降低时间复杂度，提高代码的执行效率。但是它也是出了名的难学，需要大量的题目练习才能学会。
### 动态规划与递归，分治的区别和共性
- 共性：都是要找到重复的子问题
- 区别： 动态规划：最优子结构、中途可以淘汰次优解。
### 动态规划的思路
- 找重复性
- 定义状态数组
- 写出DP方程
### 动态规划例题
- Fibonacci数列
  &emsp;&emsp;要想知道Fibonacci数列中的第n个数字是多少，就需要知道第n-1的数和第n-2的数。就可以推出dp方程既F(n) = F(n-1) + F(n-2),其中F(1) = 1;F(0) =0;可以根据递归方程写出如下代码

  ```
  // 递归方式（自顶向下）
  int Fibonacci(int n) {
    if(n <= 1) return n;
    return Fibonacci(n-1) + Fibonacci(n-2)
  }
  // 动态规划（自底向上）
  int Fibonacci(int n) {
    int pre = 0;
    int next = 1;
    for(int i =1; i < n; i++) {
      next = pre + next;
      pre = next;
    }
    return next;
  }
  ```
- 不同路径
  &emsp;&emsp;要想知道从一个格子走到右下角的格子一共有多少种不同的走法，因为机器人只可以向右走或者向下走两种选择，所以可以推出dp方程既F(i,j) = F(i+1, j) + F(i, j +1);可以根据递归方程写出如下代码
  ```
  // 递归方式（自顶向下）
   int uniquePaths(int m, int n) {
        return hepler(1,1,m,n);
    }
    int hepler(int i,int j, int m, int n) {
        if(i > m || j > n) return 0;
        else if(i == m && j == n) return 1;
        else return hepler(i +1, j ,m,n) + hepler(i, j+1,m,n);
    }
    // 动态规划（自底向上）
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i =0; i < m; i++) dp[i][0] =1;
        for(int i =0; i < n; i++) dp[0][i] =1;
        for(int i =1; i < m; i++) {
            for(int j =1; j < n; j++) {
                dp[i][j] = dp[i -1][j] + dp[i][j -1];
            }
        }
        return dp[m -1][n -1];
    }

  ```
- 最长公共子序列
  &emsp;&emsp;在考虑这道题的时候，需要将两个字符串，分别排序在x轴和y轴上枸酱二维数组，找到重复子问题就是，最长子串就为若当前比对的字符相等，则为两个字符串个去掉一个字符的字串 加一，若不同，则为字符串A去掉1个字符或字符串B去掉一个字符，最大的字串。可写代码如下
  ```
  int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        if(m < 1 || n < 1) return 0;
        int dp[m +1][n +1];
        memset(dp, 0, sizeof(dp));
        for(int i =1; i <= m; i++) {
            for(int j =1; j <= n; j++) {
                if(text1[i -1] == text2[j -1]) {
                    dp[i][j] = dp[i -1][j -1] +1;
                } else {
                    dp[i][j] = max(dp[i][j -1], dp[i -1][j]);
                }
            }
        }
        return dp[m][n];
    }
  ```


  
