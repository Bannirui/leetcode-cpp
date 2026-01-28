//Given the head of a sorted linked list, delete all nodes that have duplicate 
//numbers, leaving only distinct numbers from the original list. Return the linked 
//list sorted as well. 
//
// 
// Example 1: 
// 
// 
//Input: head = [1,2,3,3,4,4,5]
//Output: [1,2,5]
// 
//
// Example 2: 
// 
// 
//Input: head = [1,1,1,2,3]
//Output: [2,3]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is in the range [0, 300]. 
// -100 <= Node.val <= 100 
// The list is guaranteed to be sorted in ascending order. 
// 
//
// Related TopicsLinked List | Two Pointers 
//
// 👍 9582, 👎 278bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //Input: head = [1,2,3,3,4,4,5]
        //Output: [1,2,5]
        ListNode* dummy=new ListNode(-1,head);
        // [...pre] [cur...p...]
        ListNode* pre=dummy;
        while(pre && pre->next){
            ListNode* cur=pre->next;
            ListNode* p=cur;
            int cnt{0};
            while(p && p->val==cur->val){
                ++cnt;
                p=p->next;
            }
            // [cur...p-1] p
            // p is nullptr or p's val != cur's val
            if(cnt!=1){
                pre->next=p;
            }else{
                pre->next=cur;
                pre=pre->next;
            }
        }
        ListNode* ret=dummy->next;
        delete dummy;
        dummy=nullptr;
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
