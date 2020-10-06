/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return 0;
        int *pUglyNumbers = new int[n];
        pUglyNumbers[0] =1;
        int nextUglyIndex = 1;

        int *pMultiply2 = pUglyNumbers;
        int *pMultiply3 = pUglyNumbers;
        int *pMultiply5 = pUglyNumbers;

        while(nextUglyIndex < n) {
            int min = Min(*pMultiply2 *2, *pMultiply3 *3, *pMultiply5 *5);
            pUglyNumbers[nextUglyIndex] = min;
            while(*pMultiply2 *2 <=pUglyNumbers[nextUglyIndex])
                pMultiply2++;
            while(*pMultiply3 *3 <=pUglyNumbers[nextUglyIndex])
                pMultiply3++;
            while(*pMultiply5 *5 <=pUglyNumbers[nextUglyIndex])
                pMultiply5++;

            nextUglyIndex++;
        }
        int ugly = pUglyNumbers[nextUglyIndex -1];
        delete []pUglyNumbers;
        return ugly;
    }

    int Min(int num1, int num2, int num3) {
        int min = (num1 < num2) ? num1 : num2;
        return (min < num3) ? min : num3;
    }
    
};
// @lc code=end

