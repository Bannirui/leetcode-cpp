//Write an algorithm to determine if a number n is happy. 
//
// A happy number is a number defined by the following process: 
//
// 
// Starting with any positive integer, replace the number by the sum of the 
//squares of its digits. 
// Repeat the process until the number equals 1 (where it will stay), or it 
//loops endlessly in a cycle which does not include 1. 
// Those numbers for which this process ends in 1 are happy. 
// 
//
// Return true if n is a happy number, and false if not. 
//
// 
// Example 1: 
//
// 
//Input: n = 19
//Output: true
//Explanation:
//1² + 9² = 82
//8² + 2² = 68
//6² + 8² = 100
//1² + 0² + 0² = 1
// 
//
// Example 2: 
//
// 
//Input: n = 2
//Output: false
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 2³¹ - 1 
// 
//
// Related TopicsHash Table | Math | Two Pointers 
//
// 👍 11711, 👎 1621bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isHappy(int n) {
        // happy-Repeat the process until the number equals 1 (where it will stay),
        // not happy-or it loops endlessly in a cycle which does not include 1.
        std::unordered_set<int> visited;
        // set里面有数字 就会导致endlessly的循环
        while(visited.count(n)==0){
            visited.insert(n);
            int sum=0;
            while(n>0){
                int modNum=n%10;
                sum+=modNum*modNum;
                n/=10;
            }
            if(sum==1){return true;}
            n=sum;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
