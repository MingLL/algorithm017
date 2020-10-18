# 学习笔记
## 范型递归、树递归
&emsp;&emsp;说起递归永远是程序员学习进程中的一座高山，想要越过需要长时间的学习和练习。递归需要将问题翻译成以一个递推公式，只有深入到最后一个才能推导出来这个问题的解。
### 递归通用模版
```
void recursion(int level, int param) { 
  // recursion terminator 递归终止条件
  if (level > MAX_LEVEL) { 
    // process result 最终结果
    return ; 
  }

  // process current logic 当前层逻辑
  process(level, param);

  // drill down 往下递归
  recursion(level + 1, param);

  // reverse the current level status if needed 清理当前层数据
}
```
### 递归经典例题
```
// 斐波那契数列
int Fibon(int n) {
  // recursion termiantor
  if(n ==0 || n == 1) return 1;
  return Fibon(n -1) + Fibon(n -2);
}

// 爬楼梯问题 可以一层上一节台阶，也可上两层台阶，问上n层台阶有多少种方法。
// 解法：上3层台阶可以 由上2层台阶和1层台阶的解法相加得到.上N层台阶就由 上N-1层 + N-2层台阶相加得到。 
int climbStairs(int n) {
  if(n == 1) return 1;
  if(n == 2) return 2;
  return climbStairs(n -1) + climbStairs(n -2);
}
```

### 递归思考方法
- 将一个问题分解成重复的一个动作。(ps:这个过程有点困难，需要大量的练习)
  - 取某一个元素，获取不取某一个元素。(ps:[子集](https://leetcode-cn.com/problems/subsets/) 、[括号生成问题](https://leetcode-cn.com/problems/generate-parentheses/))
  - 交换数组中两个元素的位置(ps:[全排列](https://leetcode-cn.com/problems/permutations/))
- 只考虑当前层逻辑，不要想下探后要处理的逻辑
- 要能找出递推公式的可以找出递推公式
- **多练习**

### 树的递归遍历
- 前序遍历(根-左-右)
```
void preorder(TreeNode* root , vector<TreeNode*> &res) {
  if(root == null) return;
  res.push_back(root);
  preorder(root->left, res);
  preorder(root->right, res);
}
```
- 中序遍历(左-根-右)
```
void inorder(TreeNode* root, vector<TreeNode*> &res) {
  if(root == null) return;
  inorder(root->left, res);
  res.push_back(root);
  inorder(root->right, res);
}
```

- 后序遍历(左-右-根)
```
void postorder(TreeNode* root, vector<TreeNode*> &res) {
  if(root == null) return;
  postorder(root->left, res);
  postorder(root->right, res);
  res.push_back(root);
}
```



## 分治、回溯
&emsp;&emsp;分治就是将一个大问题，分解成为一个一个的小问题，最后再将他们的解组合起来，形成问题的最终解。  
&emsp;&emsp;回溯采用试错的思想，它尝试分步的去解决一个问题。在分步解决问题的过程中，当它通过尝试发现现有的分步答案不能得到有效的正确的解答的时候，它将 取消上一步甚至是上几步的计算，再通过其它的可能的分步解答再次尝试寻找问 题的答案。
### 分治模版
```
int divide_conquer(Problem *problem, int params) {
  // recursion terminator 终止条件
  if (problem == nullptr) {
    process_result
    return return_result;
  } 

  // process current problem 分解成为小问题
  subproblems = split_problem(problem, data)
  subresult1 = divide_conquer(subproblem[0], p1)
  subresult2 = divide_conquer(subproblem[1], p1)
  subresult3 = divide_conquer(subproblem[2], p1)
  ...

  // merge 将问题合并
  result = process_result(subresult1, subresult2, subresult3)
  // revert the current level status 清理当前层状态。

  return 0;
}
```


### 思考方式
- 将问题分解成可以解的小问题(ps: 最难的一步)
- 合并小问题的解形成最终问题的解(ps: 也比较难)
- **多多练习**

# 总结
&emsp;&emsp;递归，分治和回溯，现在有一些懵懂的入门，还需要大量的练习去巩固加强，后面会针对这一类的问题去练习，争取可以独立解出来问题。
