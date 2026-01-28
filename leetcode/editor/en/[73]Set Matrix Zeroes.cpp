//Given an m x n integer matrix matrix, if an element is 0, set its entire row 
//and column to 0's. 
//
// You must do it in place. 
//
// 
// Example 1: 
// 
// 
//Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
//Output: [[1,0,1],[0,0,0],[1,0,1]]
// 
//
// Example 2: 
// 
// 
//Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
//Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
// 
//
// 
// Constraints: 
//
// 
// m == matrix.length 
// n == matrix[0].length 
// 1 <= m, n <= 200 
// -2³¹ <= matrix[i][j] <= 2³¹ - 1 
// 
//
// 
// Follow up: 
//
// 
// A straightforward solution using O(mn) space is probably a bad idea. 
// A simple improvement uses O(m + n) space, but still not the best solution. 
// Could you devise a constant space solution? 
// 
//
// Related TopicsArray | Hash Table | Matrix 
//
// 👍 16858, 👎 851bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
        //Output: [[1,0,1],[0,0,0],[1,0,1]]
        // 1 1 1     1 0 1
        // 1 0 1  => 0 0 0
        // 1 1 1     1 0 1
        int m=matrix.size();
        int n=matrix[0].size();
        std::vector<bool> rowMap(m,false);
        std::vector<bool> colMap(n,false);
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j]==0){
                    if(!rowMap[i]){rowMap[i]=true;}
                    if(!colMap[j]){colMap[j]=true;}
                }
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(rowMap[i] || colMap[j]){
                    if(matrix[i][j]!=0){matrix[i][j]=0;}
                }
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
