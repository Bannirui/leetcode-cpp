//Implement pow(x, n), which calculates x raised to the power n (i.e., xⁿ). 
//
// 
// Example 1: 
//
// 
//Input: x = 2.00000, n = 10
//Output: 1024.00000
// 
//
// Example 2: 
//
// 
//Input: x = 2.10000, n = 3
//Output: 9.26100
// 
//
// Example 3: 
//
// 
//Input: x = 2.00000, n = -2
//Output: 0.25000
//Explanation: 2⁻² = 1/2² = 1/4 = 0.25
// 
//
// 
// Constraints: 
//
// 
// -100.0 < x < 100.0 
// -2³¹ <= n <= 2³¹-1 
// n is an integer. 
// Either x is not zero or n > 0. 
// -10⁴ <= xⁿ <= 10⁴ 
// 
//
// Related TopicsMath | Recursion 
//
// 👍 11437, 👎 10484bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double myPow(double x, int n) {
        return myPow(x, (long long)n);
    }

    double myPow(double x, long long n){
        // base
        if(x==1){return 1;}
        if(n<0){return 1/myPow(x,-n);}
        if(n==0){return 1;}
        if(n==1){return x;}
        if((n&1)==1){return myPow(x,n-1)*x;}
        double tmp=myPow(x,n>>1);
        return tmp*tmp;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
