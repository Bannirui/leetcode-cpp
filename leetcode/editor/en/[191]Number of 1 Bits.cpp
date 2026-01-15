//Given a positive integer n, write a function that returns the number of set 
//bits in its binary representation (also known as the Hamming weight). 
//
// 
// Example 1: 
//
// 
// Input: n = 11 
// 
//
// Output: 3 
//
// Explanation: 
//
// The input binary string 1011 has a total of three set bits. 
//
// Example 2: 
//
// 
// Input: n = 128 
// 
//
// Output: 1 
//
// Explanation: 
//
// The input binary string 10000000 has a total of one set bit. 
//
// Example 3: 
//
// 
// Input: n = 2147483645 
// 
//
// Output: 30 
//
// Explanation: 
//
// The input binary string 1111111111111111111111111111101 has a total of 
//thirty set bits. 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 2³¹ - 1 
// 
//
// 
//Follow up: If this function is called many times, how would you optimize it?
//
// Related TopicsDivide and Conquer | Bit Manipulation 
//
// 👍 7078, 👎 1364bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int hammingWeight(int n) {
        int ret=0;
        while(n){
            if(n&1){++ret;}
            n>>=1;
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
