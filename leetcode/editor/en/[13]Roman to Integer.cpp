//Roman numerals are represented by seven different symbols: I, V, X, L, C, D 
//and M. 
//
// 
//Symbol       Value
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000 
//
// For example, 2 is written as II in Roman numeral, just two ones added 
//together. 12 is written as XII, which is simply X + II. The number 27 is written as 
//XXVII, which is XX + V + II. 
//
// Roman numerals are usually written largest to smallest from left to right. 
//However, the numeral for four is not IIII. Instead, the number four is written as 
//IV. Because the one is before the five we subtract it making four. The same 
//principle applies to the number nine, which is written as IX. There are six 
//instances where subtraction is used: 
//
// 
// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900. 
// 
//
// Given a roman numeral, convert it to an integer. 
//
// 
// Example 1: 
//
// 
//Input: s = "III"
//Output: 3
//Explanation: III = 3.
// 
//
// Example 2: 
//
// 
//Input: s = "LVIII"
//Output: 58
//Explanation: L = 50, V= 5, III = 3.
// 
//
// Example 3: 
//
// 
//Input: s = "MCMXCIV"
//Output: 1994
//Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 15 
// s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M'). 
// It is guaranteed that s is a valid roman numeral in the range [1, 3999]. 
// 
//
// Related TopicsHash Table | Math | String 
//
// 👍 17211, 👎 1194bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int romanToInt(string s) {
        //Input: s = "MCMXCIV"
        //Output: 1994
        //Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
        // 正常 前大后小
        // 减法 前小后大
        //Symbol       Value
        //I             1
        //V             5
        //X             10
        //L             50
        //C             100
        //D             500
        //M             1000
        int map[26];
        map['C'-'A']=100;
        map['D'-'A']=500;
        map['I'-'A']=1;
        map['L'-'A']=50;
        map['M'-'A']=1000;
        map['X'-'A']=10;
        map['V'-'A']=5;
        int ret=0;
        for(int i=0,sz=s.size();i<sz;i++){
            char cur=s[i];
            int curIdx=cur-'A';
            if(i==sz-1){
                ret+=map[curIdx];
            }else{
                char next=s[i+1];
                int nextIdx=next-'A';
                if(map[curIdx]<map[nextIdx]){ret-=map[curIdx];}
                else{ret+=map[curIdx];}
            }
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
