//Given an integer n, return true if it is a power of four. Otherwise, return 
//false. 
//
// An integer n is a power of four, if there exists an integer x such that n == 
//4ˣ. 
//
// 
// Example 1: 
// Input: n = 16
//Output: true
// 
// Example 2: 
// Input: n = 5
//Output: false
// 
// Example 3: 
// Input: n = 1
//Output: true
// 
// 
// Constraints: 
//
// 
// -2³¹ <= n <= 2³¹ - 1 
// 
//
// 
//Follow up: Could you solve it without loops/recursion?
//
// Related TopicsMath | Bit Manipulation | Recursion 
//
// 👍 4419, 👎 417bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPowerOfFour(int n) {
        // base
        if(n==0){return false;}
        if(n==1){return true;}
        return ((n%4)==0) && this->isPowerOfFour(n>>2);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
