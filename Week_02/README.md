# 学习笔记
## 哈希表、映射、集合
### 哈希表、映射
&emsp;&emsp;哈希表也叫散列表，有的人也称为Hash表，根据关键码值从而直接访问数据的一种数据结构。加快访问数据的速度。
#### 特点
- 取值和查找值的时间复杂度为O(1)，最坏情况下为O(n)*(ps:当出现冲突的时候，哈希表退化成一个链表)*
- key和value的映射通过散列函数(哈希函数、Hash函数)得到映射关系。存放数据的地方成为哈希表或者散列表
- 哈希函数中会出现冲突现象既两个value的值对应到一个key上面。使用链表法，线性探测法解决冲突。
#### 工程应用
- (LRU Cache)缓存：使用哈希表存储缓存的数据，将查找的速度降为O(1)
- 键值对存储(Redis)
### 集合
&emsp;&emsp;集合，一组没有重复数据的集合。
#### 特点
- 没有重复的数据的集合
- 底层使用HashMap实现，直接将数据最为key传入HashMap中
### 相关例题
- [有效的字母异位词](https://leetcode-cn.com/problems/group-anagrams/submissions/)
&emsp;&emsp;使用HashMap存储每个字母出现的次数，相等就是异位词
```
  bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }
        // 使用数组最为Hash表，存储字母出现的个数
        vector<int> vectors(26,0);
        for(int i =0; i< s.length(); i++) {
          // 第一单词出现则 +1;
            vectors[s[i] - 'a']++;
          // 第二单词出现则 -1;
            vectors[t[i] - 'a']--;
        }
        // 判断Hash表的数据是不是都是0; 不是则不是异味字符
        for(int a : vectors) {
            if(a != 0) {
                return false;
            }
        }
        return true;
    } 
```
- [字母异位词分组](https://leetcode-cn.com/problems/valid-anagram/description/)
&emsp;&emsp;遍历每一个单词并且排序，将排序后的字符作为key存储字符串
```
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> map;
        for(string s :strs) {
            string t = s;
            sort(t.begin(), t.end());
            map[t].push_back(s);
        }
        for(auto& a: map) {
            res.push_back(a.second);
        }
        return res;
    }
```
- [两数之和](https://leetcode-cn.com/problems/two-sum/description/)
&emsp;&emsp;将数组的值和下标保存在Hash表中，用target- 遍历数组中的值，若在Hash表里出现过则返回。
```
vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = map.find(target - nums[i]);
            if (it != map.end()) {
                return {it->second, i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
```
## 树、二叉树、二叉搜索树
&emsp;&emsp;优化算法的方式：1、空间换时间。2、升维。二叉树就是将一维的数据结构升为二维的数据结构，并作出一些规则，提升查找速度。
### 基本数据结构
```
// 二叉树
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *righe;
};
// 树
struct Tree {
  int val;
  Vector<TreeNode* > children; 
}
```
### 知识点
- 前序遍历(根-左-右)
```
// 二叉树遍历
void inorderTraversal(TreeNode* root) {
  if(root == null) return;
  print("%d",root->val);
  inorderTraversal(root->left);
  inorderTraversal(root->right);
}
```
- 中序遍历(左-根-右) 
```
// 二叉树遍历
void inorderTraversal(TreeNode* root) {
  if(root == null) return;
  inorderTraversal(root->left);
  print("%d",root->val);
  inorderTraversal(root->right);
}
```
- 后序遍历(左-右-根) 
```
// 二叉树遍历
void inorderTraversal(TreeNode* root) {
  if(root == null) return;
  inorderTraversal(root->left);
  inorderTraversal(root->right);
  print("%d",root->val);
}
```
### 二叉搜素树
&emsp;&emsp;二叉搜索树，也称二叉排序树、有序二叉树(Ordered Binary Tree)、排序二叉树(Sorted Binary Tree)。
#### 特点
- 左子树上所有结点的值均小于它的根结点的值;
- 右子树上所有结点的值均大于它的根结点的值;
- 以此类推:左、右子树也分别为二叉查找树。 (这就是 重复性!
- 中序遍历是有序的

## 堆Heap和二叉堆Binary Heap
&emsp;&emsp;可以迅速找到一堆数中的最大值或者最小值的数据结构
### 特点
- 找到最大值O(1)
- 删除最大值O(logN)
- 插入元素O(logN)或O(1)*(ps:插入的值是最小的)*
### 相关例题
- [滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/)
&emsp;&emsp;暂时没有理解
