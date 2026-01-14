//Given a 32-bit integer num, return a string representing its hexadecimal 
//representation. For negative integers, two’s complement method is used. 
//
// All the letters in the answer string should be lowercase characters, and 
//there should not be any leading zeros in the answer except for the zero itself. 
//
// Note: You are not allowed to use any built-in library method to directly 
//solve this problem. 
//
// 
// Example 1: 
// Input: num = 26
//Output: "1a"
// 
// Example 2: 
// Input: num = -1
//Output: "ffffffff"
// 
// 
// Constraints: 
//
// 
// -2³¹ <= num <= 2³¹ - 1 
// 
//
// Related TopicsMath | String | Bit Manipulation 
//
// 👍 1424, 👎 228bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string toHex(int num) {
        if(num==0){return "0";}
        unsigned int n=static_cast<unsigned int>(num);
        std::string base="0123456789abcdef";
        std::string ret;
        while(n){
            ret.insert(ret.begin(),base[n&0xf]);
            n>>=4;
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
