//You are given an n x n 2D matrix representing an image, rotate the image by 90
// degrees (clockwise). 
//
// You have to rotate the image in-place, which means you have to modify the 
//input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation. 
//
// 
// Example 1: 
// 
// 
//Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [[7,4,1],[8,5,2],[9,6,3]]
// 
//
// Example 2: 
// 
// 
//Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
//Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
// 
//
// 
// Constraints: 
//
// 
// n == matrix.length == matrix[i].length 
// 1 <= n <= 20 
// -1000 <= matrix[i][j] <= 1000 
// 
//
// Related TopicsArray | Math | Matrix 
//
// 👍 19603, 👎 947bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 1 2 3
        // 4 5 6
        // 7 8 9

        // 7 4 1
        // 8 5 2
        // 9 6 3
        int n=matrix.size();
        // [0,0]->[n-1,n-1]
        int x1=0,x2=n-1;
        while(x1<=x2){
            this->rotateByCircle(matrix,x1,x1,x2,x2);
            ++x1;
            --x2;
        }
    }

    void rotateByCircle(std::vector<std::vector<int>>& matrix, int x1, int y1, int x2, int y2){
        // base
        if(x1==x2){return;}
        // 1 2 3
        // 4   6
        // 7 8 9
        for(int i=0;i+y1!=y2;++i){
            int tmp=matrix[x1][y1+i];
            matrix[x1][y1+i]=matrix[x2-i][y1];
            matrix[x2-i][y1]=matrix[x2][y2-i];
            matrix[x2][y2-i]=matrix[x1+i][y2];
            matrix[x1+i][y2]=tmp;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
