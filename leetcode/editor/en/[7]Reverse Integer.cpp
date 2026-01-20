//Given a signed 32-bit integer x, return x with its digits reversed. If 
//reversing x causes the value to go outside the signed 32-bit integer range [-2³¹, 2³¹ -
// 1], then return 0. 
//
// Assume the environment does not allow you to store 64-bit integers (signed 
//or unsigned). 
//
// 
// Example 1: 
//
// 
//Input: x = 123
//Output: 321
// 
//
// Example 2: 
//
// 
//Input: x = -123
//Output: -321
// 
//
// Example 3: 
//
// 
//Input: x = 120
//Output: 21
// 
//
// 
// Constraints: 
//
// 
// -2³¹ <= x <= 2³¹ - 1 
// 
//
// Related TopicsMath 
//
// 👍 15158, 👎 13946bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int reverse(int x) {
        if(x<0){return -this->reversePositive(0-(long long)x);}
        else{return this->reversePositive((long long)x);}
    }

    int reversePositive(long long x){
        // base
        if(x==0){return 0;}
        int ret=0;
        while(x!=0){
            int num=x%10;
            // 溢出检查
            if(ret>(INT_MAX-num)/10){return 0;}
            ret=ret*10+num;
            x/=10;
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
