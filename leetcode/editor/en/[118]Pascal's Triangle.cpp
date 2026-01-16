//Given an integer numRows, return the first numRows of Pascal's triangle. 
//
// In Pascal's triangle, each number is the sum of the two numbers directly 
//above it as shown: 
// 
// 
// Example 1: 
// Input: numRows = 5
//Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// 
// Example 2: 
// Input: numRows = 1
//Output: [[1]]
// 
// 
// Constraints: 
//
// 
// 1 <= numRows <= 30 
// 
//
// Related TopicsArray | Dynamic Programming 
//
// 👍 14745, 👎 559bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // Input: numRows = 5
        //Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
        std::vector<std::vector<int>> ret;
        for(int i=0;i<numRows;++i){
            std::vector<int> cur(i+1,1);
            if(i!=0){
                std::vector<int> pre=ret[i-1];
                for(int j=0;j<=i;++j){
                    if(j!=0 && j!=i){
                        cur[j]=pre[j-1]+pre[j];
                    }
                }
            }
            ret.push_back(cur);
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
