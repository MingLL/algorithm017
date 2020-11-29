# 学习笔记
## 高级动态规划
&emsp;&emsp;高级动态规划的基础就是练习好，递归，分治，回溯还有定义状态转移方程。
### 复习基础
- 递归模版
```
  void recur(int level, int parm) {
    // 递归终止条件
    if(level > MAX_LEVEL) {
      // 保存结果
      return;
    }
    // 处理当前层逻辑
    // 下探到下一层
    recur(level +1, parm);

    // 清理当前层状态
  }
```
- 分治模版
```
  int divide_conquer(Pragram *pragram, int parms) {
    if(pragram == null) {
      // 处理结果
      return return_result;
    }
    // 拆分问题
    subproblems = split_problem(problem, data);
    subresult1 = divide_conquer(subproblem[0], p1);
    subresult2 = divide_conquer(subproblem[1], p1);
    subresult3 = divide_conquer(subproblem[2], p1);
    ...

    // 合并结果
    result = merge(subresult1, subresult2, subresult3..);
    // 清理当前层;
    return result;
  }
```  

### 感触
- 不能人肉递归
- 找到最近最简方法
- 数学归纳法思想



## 字符串
&emsp;&emsp;字符串是编程中最常见的数据结构，每一个编程语言都有实现的Stirng(C语言除外)。
### 字符串中的算法
- 最长回文子串
  - 暴力求解(O(n^3));
  - 中心扩散法(O(n^2));
  ```
  class Solution {
  public:
    string longestPalindrome(string s) {
        if(s.size() < 1) return "";
        int maxStr =0;
        int begin =0;
        for(int i =0; i < s.size();i++) {
            int len1 = expandAroundString(s, i, i);
            int len2 = expandAroundString(s, i, i +1);
            int len = len1 > len2 ? len1 : len2;
            if(len > maxStr) {
                maxStr = len;
                begin = i - (len -1)/2;
            }
        }
        return s.substr(begin, maxStr);
    }
    int expandAroundString(const string& s, int left, int right) {
        int L = left, R = right;
        while(L >= 0 && R < s.size() && s[L] == s[R]) {
            L--;
            R++;
        }
        return R - L -1;
    }
  };
  ```
  - 动态规划






