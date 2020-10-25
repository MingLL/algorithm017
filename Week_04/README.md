# 学习笔记
## 深度优先搜索、广度优先搜索
&emsp;&emsp; 遍历是每一个数据结构的基本方法，一维数据结构的遍历非常简单使用循环就可以完成，二维数据的遍历就需要认真的思考一下了。
### 分类
- 深度优先遍历(使用递归实现，一直深入找到遍历不下去的，在回溯，遍历完所有的节点)
```
// 保存已经遍历过的数组
map<int, int> visited;
void dfs(Node* root) {
  // terminator
  if (!root) return ;

  if (visited.count(root->val)) {
    // already visited
    return ;
  }

  visited[root->val] = 1;

  // process current node here. 
  // ...
  for (int i = 0; i < root->children.size(); ++i) {
    dfs(root->children[i]);
  }
  return ;
}
```

- 广度优先遍历(使用队列进行遍历， 将节点的儿子都放入队列中，从队列中取元素进行遍历)
```
void bfs(Node* root) {
  map<int, int> visited;
  if(!root) return ;

  queue<Node*> queueNode;
  queueNode.push(root);

  while (!queueNode.empty()) {
    Node* node = queueNode.top();
    queueNode.pop();
    if (visited.count(node->val)) continue;
    visited[node->val] = 1;

    for (int i = 0; i < node->children.size(); ++i) {
        queueNode.push(node->children[i]);
    }
  }

  return ;
}
```
### 例题
- [二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)
&emsp;&emsp;套BSF的模版，将结果保存到一个集合当中
```
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        deque<TreeNode*> queue;
        queue.push_back(root);
        while(!queue.empty()) {
            int size = queue.size();
            vector<int> temp;
            for(int i =0; i < size; i++) {
                TreeNode* node = queue.front();
                queue.pop_front();
                temp.push_back(node->val);
                if(node->left) {
                    queue.push_back(node->left);
                }
                if(node->right) {
                    queue.push_back(node->right);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
```

## 贪心算法
&emsp;&emsp;贪心算法是一种在每一步选择中都采取在当前状态下最好或最优(即最有利)的选择，从而希望导致结果是全局最好或最优的算法。

### 例题
- [买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/description/)
&emsp;&emsp; 如果某一天的金额比它后一天的小，则在当天买入，并且在明天卖出。遍历所有的，得到结果就是最终结果。
```
int maxProfit(vector<int>& prices) {
    int maxPrice =0;
    for(int i = 0; i < prices.size()-1; i++) {
        if(prices[i] < prices[i +1]) {
            maxPrice += prices[i +1] - prices[i];
        }
    }
    return maxPrice;
}
```
- [柠檬水找零](https://leetcode-cn.com/problems/lemonade-change/description/)
&emsp;&emsp; 当收入为10元，查看是否含有5元的零钱， 若收入为20元后，查看是否含有10元和5元的零钱 或者 3个5元零钱。
```
bool lemonadeChange(vector<int>& bills) {
    int fiveBills =0, tenBills =0;
    for(int i =0; i < bills.size(); i++) {
        if(bills[i] == 5) {
            fiveBills++;
        }
        if(bills[i] ==10) {
            if(fiveBills < 1) {
                return false;
            }
            fiveBills--;
            tenBills++;
        }
        if(bills[i] == 20) {
            if(tenBills >0 && fiveBills >0){
                fiveBills--;
                tenBills--;
            } else if (fiveBills > 3){
                fiveBills -= 3;
            }else{
                return false;
            }
        }
    }
    return true;
}
```


## 二分查找
&emsp;&emsp; 二分查找是在**有序**集合中，以时间复杂度为O(log n) 更快的查找出来元素。

### 使用条件
- 目标函数的单调性
- 存在上下界
- 可以使用索引访问

### 代码模版
```
int binarySearch(const vector<int>& nums, int target) {
	int left = 0, right = (int)nums.size()-1;
	
	while (left <= right) {
		int mid = left + (right - left)/ 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] < target) left = mid + 1;
		else right = mid - 1;
	}
	
	return -1;
}
```




### 课后问题
&emsp;&emsp;使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方。  (ps: 数组升序排序)
```
int solution(vector<int>& nums) {
  int left =0, right =nums.size() -1;
  while(left < right) {
    int mid = left + (right -left) /2;
    if(nums[mid +1] < nums[mid]) {
      left = mid +1;
      break;
    }
    // 判断整个数组是否有序
    if(nums[mid] > nums[left] && nums[mid] < nums[right]) {
        break;
        // 左边是否有序， 有序在右边查找，反之则在左边查找
    } else if(nums[mid] > nums[left]) {
        left = mid;
    } else {
        right = mid;
    }
  }
  return left;
}
```