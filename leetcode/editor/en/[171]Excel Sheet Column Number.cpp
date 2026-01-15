//Given a string columnTitle that represents the column title as appears in an 
//Excel sheet, return its corresponding column number. 
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
//Input: columnTitle = "A"
//Output: 1
// 
//
// Example 2: 
//
// 
//Input: columnTitle = "AB"
//Output: 28
// 
//
// Example 3: 
//
// 
//Input: columnTitle = "ZY"
//Output: 701
// 
//
// 
// Constraints: 
//
// 
// 1 <= columnTitle.length <= 7 
// columnTitle consists only of uppercase English letters. 
// columnTitle is in the range ["A", "FXSHRXW"]. 
// 
//
// Related TopicsMath | String 
//
// 👍 5058, 👎 396bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int titleToNumber(string columnTitle) {
        // A-0-1
        // B-1-2
        // Z-25-26
        int ret=0;
        for(auto it=columnTitle.begin();it!=columnTitle.end();++it){
            ret=ret*26+(*it-'A')+1;
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
