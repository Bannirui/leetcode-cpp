//Given a positive integer num, return true if num is a perfect square or false 
//otherwise. 
//
// A perfect square is an integer that is the square of an integer. In other 
//words, it is the product of some integer with itself. 
//
// You must not use any built-in library function, such as sqrt. 
//
// 
// Example 1: 
//
// 
//Input: num = 16
//Output: true
//Explanation: We return true because 4 * 4 = 16 and 4 is an integer.
// 
//
// Example 2: 
//
// 
//Input: num = 14
//Output: false
//Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an 
//integer.
// 
//
// 
// Constraints: 
//
// 
// 1 <= num <= 2³¹ - 1 
// 
//
// Related TopicsMath | Binary Search 
//
// 👍 4607, 👎 334bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPerfectSquare(int num) {
        // base
        if(num==1){return true;}
		long long target=static_cast<long long>(num);
        int lo=1,hi=(num>>1);
        while(lo<=hi){
            int mid=lo+((hi-lo)>>1);
            long long cur=(long long)mid*mid;
            if(cur==target){return true;}
            if(cur<target){lo=mid+1;}
            else{hi=mid-1;}
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
