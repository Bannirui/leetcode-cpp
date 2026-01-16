//Given an integer rowIndex, return the rowIndexᵗʰ (0-indexed) row of the 
//Pascal's triangle. 
//
// In Pascal's triangle, each number is the sum of the two numbers directly 
//above it as shown: 
// 
// 
// Example 1: 
// Input: rowIndex = 3
//Output: [1,3,3,1]
// 
// Example 2: 
// Input: rowIndex = 0
//Output: [1]
// 
// Example 3: 
// Input: rowIndex = 1
//Output: [1,1]
// 
// 
// Constraints: 
//
// 
// 0 <= rowIndex <= 33 
// 
//
// 
// Follow up: Could you optimize your algorithm to use only O(rowIndex) extra 
//space? 
//
// Related TopicsArray | Dynamic Programming 
//
// 👍 5242, 👎 366bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // rowIndex is 1-based
    vector<int> getRow(int rowIndex) {
        // Input: rowIndex = 3
        //Output: [1,3,3,1]
        // base
        std::vector<int> pre;
        std::vector<int> cur;
        for(int i=0;i<=rowIndex;++i){
            cur=std::vector<int>(i+1,1);
            for(int j=0;j<=i;++j){
                if(j!=0 && j!=i){
                    cur[j]=pre[j-1]+pre[j];
                }
            }
            pre=std::vector<int>(cur);
        }
        return pre;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
