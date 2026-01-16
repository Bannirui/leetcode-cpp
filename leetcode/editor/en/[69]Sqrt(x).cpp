//Given a non-negative integer x, return the square root of x rounded down to 
//the nearest integer. The returned integer should be non-negative as well. 
//
// You must not use any built-in exponent function or operator. 
//
// 
// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python. 
// 
//
// 
// Example 1: 
//
// 
//Input: x = 4
//Output: 2
//Explanation: The square root of 4 is 2, so we return 2.
// 
//
// Example 2: 
//
// 
//Input: x = 8
//Output: 2
//Explanation: The square root of 8 is 2.82842..., and since we round it down 
//to the nearest integer, 2 is returned.
// 
//
// 
// Constraints: 
//
// 
// 0 <= x <= 2³¹ - 1 
// 
//
// Related TopicsMath | Binary Search 
//
// 👍 9461, 👎 4626bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int mySqrt(int x) {
        int lo=1,hi=x;
        int ret=0;
        while(lo<=hi){
            int mid=lo+((hi-lo)>>1);
            long long cur=(long long)mid*mid;
            if(cur==x){
                return mid;
            }else if(cur>x){
                hi=mid-1;
            }else{
                ret=mid;
                lo=mid+1;
            }
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
