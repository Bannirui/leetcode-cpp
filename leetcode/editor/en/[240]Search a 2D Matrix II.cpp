//Write an efficient algorithm that searches for a value target in an m x n 
//integer matrix matrix. This matrix has the following properties: 
//
// 
// Integers in each row are sorted in ascending from left to right. 
// Integers in each column are sorted in ascending from top to bottom. 
// 
//
// 
// Example 1: 
// 
// 
//Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[1
//8,21,23,26,30]], target = 5
//Output: true
// 
//
// Example 2: 
// 
// 
//Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[1
//8,21,23,26,30]], target = 20
//Output: false
// 
//
// 
// Constraints: 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= n, m <= 300 
// -10⁹ <= matrix[i][j] <= 10⁹ 
// All the integers in each row are sorted in ascending order. 
// All the integers in each column are sorted in ascending order. 
// -10⁹ <= target <= 10⁹ 
// 
//
// Related TopicsArray | Binary Search | Divide and Conquer | Matrix 
//
// 👍 12991, 👎 229bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Integers in each row are sorted in ascending from left to right.
        // Integers in each column are sorted in ascending from top to bottom.
        // 1, 4, 7, 11,15
        // 2, 5, 8, 12,19
        // 3, 6, 9, 16,22
        // 10,13,14,17,24
        // 18,21,23,26,30
        // 右上角->左下角
        int m=matrix.size();
        int n=matrix[0].size();
        return search(matrix,0,n-1,target);
    }
private:
    bool search(std::vector<std::vector<int>>& matrix,int r,int c,int target){
        // base
        if(r==matrix.size() || c<0){return false;}
        if(matrix[r][c]==target){return true;}
        if(matrix[r][c]<target){
            ++r;
        }else{
            --c;
        }
        return search(matrix,r,c,target);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
