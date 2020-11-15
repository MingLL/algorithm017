/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */

// @lc code=start
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
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int size = M.size();
        UF *uf = new UF(size);
        for(int i =0; i <size; i++) {
            for(int j = i; j< size; j++) {
                if(M[i][j] ==1) {
                    uf->Union(i, j);
                }
            }
        }
        return uf->getCount();
    }
};
// @lc code=end

