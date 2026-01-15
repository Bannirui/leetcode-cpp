//Given an integer columnNumber, return its corresponding column title as it 
//appears in an Excel sheet. 
//
// For example: 
//
// 
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28 
//...
// 
//
// 
// Example 1: 
//
// 
//Input: columnNumber = 1
//Output: "A"
// 
//
// Example 2: 
//
// 
//Input: columnNumber = 28
//Output: "AB"
// 
//
// Example 3: 
//
// 
//Input: columnNumber = 701
//Output: "ZY"
// 
//
// 
// Constraints: 
//
// 
// 1 <= columnNumber <= 2³¹ - 1 
// 
//
// Related TopicsMath | String 
//
// 👍 6002, 👎 905bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string convertToTitle(int columnNumber) {
        std::string ret;
        // base 26 %26=[0...25]
        // 1-0-A
        // 2-1-B
        // 26-25-Z
        while(columnNumber){
            columnNumber--;
            ret.insert(ret.begin(),'A'+(columnNumber%26));
            columnNumber/=26;
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
