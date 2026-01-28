//Given two integers n and k, return all possible combinations of k numbers 
//chosen from the range [1, n]. 
//
// You may return the answer in any order. 
//
// 
// Example 1: 
//
// 
//Input: n = 4, k = 2
//Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
//Explanation: There are 4 choose 2 = 6 total combinations.
//Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to 
//be the same combination.
// 
//
// Example 2: 
//
// 
//Input: n = 1, k = 1
//Output: [[1]]
//Explanation: There is 1 choose 1 = 1 total combination.
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 20 
// 1 <= k <= n 
// 
//
// Related TopicsBacktracking 
//
// 👍 8837, 👎 250bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        //chosen from the range [1, n].
        std::vector<std::vector<int>> paths;
        if(k==0 || n<1){return paths;}
        std::vector<int> path;
        std::vector<bool> visit(n+1,false);
        backTrack(n,1,visit,k,path,paths);
        return paths;
    }

    void backTrack(int n,int idx,std::vector<bool>& visit,int k,std::vector<int>& path,std::vector<std::vector<int>>& paths){
        // base
        if(path.size()==k){
            paths.push_back(path);
            return;
        }
        for(int i=idx;i<=n;++i){
            if(visit[i]){continue;}
            path.push_back(i);
            visit[i]=true;
            backTrack(n,i,visit,k,path,paths);
            visit[i]=false;;
            path.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
