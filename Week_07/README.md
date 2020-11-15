# 学习笔记
## 字典树和并查集
### 字典树
&emsp;&emsp; 字典树，既Trie树，又称单词查找树或键树，是一种树形结构。典型应用是用于统计和排序大量的字符串(但不仅限于字符串)，所以经常被搜索引擎系统用于文本词频统计。
#### 基本性质
- 结点本身不存完整单词
- 从根结点到某一结点，路径上经过的字符连接起来，为该结点对应的 字符串;
- 每个结点的所有子结点路径代表的字符都不相同
#### 实现代码
```
class Trie {
private:
    bool is_end;
    Trie* next[26];
public:
    /** Initialize your data structure here. */
    Trie() {
        is_end = false;
        memset(next, 0, sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        for(char c : word) {
            if(node->next[c - 'a'] == nullptr) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = this;
        for(char c : word) {
            node = node->next[c - 'a'];
            if(node == nullptr) return false;
        }
        return node->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node = this;
        for(char c : prefix) {
            node = node->next[c - 'a'];
            if(node == nullptr) return false;
        }
        return true;
    }
};
```

### 并查集
&emsp;&emsp; 为解决组团、配对等问题等一种数据结构
#### 基本操作
- makeSet(s):建立一个新的并查集，其中包含 s 个单元素集合。
- unionSet(x, y):把元素 x 和元素 y 所在的集合合并，要求 x 和 y 所在的集合不相交，如果相交则不合并。
- find(x):找到元素 x 所在的集合的代表，该操作也可以用于判断两个元 素是否位于同一个集合，只要将它们各自的代表比较一下就可以了。
#### 实现方式
```
class UF {
private:
    int count;
    int* parent;
    int* size;
    
    int find(int n) {
        while(parent[n] != n) {
            parent[n] = parent[parent[n]];
            n = parent[n];
        }
        return n;
    } 
public:
    UF(int n) {
        count = n;
        this->parent = new int[n];
        this->size = new int[n];
        for(int i = 0; i <n; i++) {
            parent[i] = i;
            size[i] = i;
        }
    }

    void Union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ) return;
        if(size[rootP] > size[rootQ]) {
            parent[rootQ] = parent[rootP];
            size[rootP] += size[rootQ];
        } else {
            parent[rootP] = parent[rootQ];
            size[rootQ] += size[rootP];
        }
        count--;
    }

    int getCount() {
        return count;
    }
  
};
```


### 高级搜索

### 红黑树和AVL树
