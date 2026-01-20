//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number 
//of rows like this: (you may want to display this pattern in a fixed font for 
//better legibility) 
//
// 
//P   A   H   N
//A P L S I I G
//Y   I   R
// 
//
// And then read line by line: "PAHNAPLSIIGYIR" 
//
// Write the code that will take a string and make this conversion given a 
//number of rows: 
//
// 
//string convert(string s, int numRows);
// 
//
// 
// Example 1: 
//
// 
//Input: s = "PAYPALISHIRING", numRows = 3
//Output: "PAHNAPLSIIGYIR"
// 
//
// Example 2: 
//
// 
//Input: s = "PAYPALISHIRING", numRows = 4
//Output: "PINALSIGYAHRPI"
//Explanation:
//P     I    N
//A   L S  I G
//Y A   H R
//P     I
// 
//
// Example 3: 
//
// 
//Input: s = "A", numRows = 1
//Output: "A"
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 1000 
// s consists of English letters (lower-case and upper-case), ',' and '.'. 
// 1 <= numRows <= 1000 
// 
//
// Related TopicsString 
//
// 👍 9144, 👎 15788bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string convert(string s, int numRows) {
        std::vector<std::string> strs;
        for(int i=0;i<numRows;++i){
            std::string tmp;
            strs.push_back(tmp);
        }
        int n=s.size();
        int j=0;
        int k=-1;
        int delta=1;
        while(j<n){
            k+=delta;
            if(k>numRows-1){k=numRows-1;}
            if(k<0){k=0;}
            if(k==numRows-1){
                delta=-1;
            }else if(k==0){
                delta=1;
            }
            strs[k].push_back(s[j]);
            ++j;
        }
        std::string ret;
        for(int i=0;i<numRows;++i){
            ret.append(strs[i]);
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
