//Reverse bits of a given 32 bits signed integer. 
//
// 
// Example 1: 
//
// 
// Input: n = 43261596 
// 
//
// Output: 964176192 
//
// Explanation: 
//
// 
// 
// 
// Integer 
// Binary 
// 
// 
// 43261596 
// 00000010100101000001111010011100 
// 
// 
// 964176192 
// 00111001011110000010100101000000 
// 
// 
// 
//
// Example 2: 
//
// 
// Input: n = 2147483644 
// 
//
// Output: 1073741822 
//
// Explanation: 
//
// 
// 
// 
// Integer 
// Binary 
// 
// 
// 2147483644 
// 01111111111111111111111111111100 
// 
// 
// 1073741822 
// 00111111111111111111111111111110 
// 
// 
// 
//
// 
// Constraints: 
//
// 
// 0 <= n <= 2³¹ - 2 
// n is even. 
// 
//
// 
// Follow up: If this function is called many times, how would you optimize it? 
//
//
// Related TopicsDivide and Conquer | Bit Manipulation 
//
// 👍 5576, 👎 1642bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int reverseBits(int n) {
        // 2147483644
        // 01111111111111111111111111111100
        // 1073741822
        // 00111111111111111111111111111110
        int ret=0;
        for(int i=0;i<32;++i){
            ret<<=1;
            ret|=(n&1);
            n>>=1;
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
