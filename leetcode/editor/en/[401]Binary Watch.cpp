//A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6
//LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or 
//one, with the least significant bit on the right. 
//
// 
// For example, the below binary watch reads "4:51". 
// 
//
// 
//
// Given an integer turnedOn which represents the number of LEDs that are 
//currently on (ignoring the PM), return all possible times the watch could represent. 
//You may return the answer in any order. 
//
// The hour must not contain a leading zero. 
//
// 
// For example, "01:00" is not valid. It should be "1:00". 
// 
//
// The minute must consist of two digits and may contain a leading zero. 
//
// 
// For example, "10:2" is not valid. It should be "10:02". 
// 
//
// 
// Example 1: 
// Input: turnedOn = 1
//Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00
//"]
// 
// Example 2: 
// Input: turnedOn = 9
//Output: []
// 
// 
// Constraints: 
//
// 
// 0 <= turnedOn <= 10 
// 
//
// Related TopicsBacktracking | Bit Manipulation 
//
// 👍 1564, 👎 2863bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        //A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6
		//LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or
        std::vector<string> ret;
        for(int i=0;i<12;++i){
            for(int j=0;j<60;++j){
                // 1的个数
                int cnt1=std::bitset<4>(i).count();
                // 1的个数
                int cnt2=std::bitset<6>(j).count();
                if(cnt1+cnt2==turnedOn){
                    std::string str=std::to_string(i)+":"+(j<10?"0":"")+std::to_string(j);
                    ret.push_back(str);
                }
            }
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
