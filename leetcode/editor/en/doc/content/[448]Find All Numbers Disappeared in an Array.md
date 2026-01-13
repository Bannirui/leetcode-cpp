<p>Given an array <code>nums</code> of <code>n</code> integers where <code>nums[i]</code> is in the range <code>[1, n]</code>, return <em>an array of all the integers in the range</em> <code>[1, n]</code> <em>that do not appear in</em> <code>nums</code>.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<pre><strong>Input:</strong> nums = [4,3,2,7,8,2,3,1]
<strong>Output:</strong> [5,6]
</pre>
<p><strong class="example">Example 2:</strong></p> 
<pre><strong>Input:</strong> nums = [1,1]
<strong>Output:</strong> [2]
</pre> 
<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>n == nums.length</code></li> 
 <li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li> 
 <li><code>1 &lt;= nums[i] &lt;= n</code></li> 
</ul>

<p>&nbsp;</p> 
<p><strong>Follow up:</strong> Could you do it without extra space and in <code>O(n)</code> runtime? You may assume the returned list does not count as extra space.</p>

<details><summary><strong>Related Topics</strong></summary>Array | Hash Table</details><br>

<div>👍 10189, 👎 541<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/issues' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.online/algo/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.online/algo/' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>

<div id="labuladong"><hr>

**通知：为满足广大读者的需求，网站上架 [速成目录](https://labuladong.online/algo/intro/quick-learning-plan/)，如有需要可以看下，谢谢大家的支持~**

<details><summary><strong>labuladong 思路</strong></summary>


<div id="labuladong_solution_zh">

## 基本思路

这道题的常规的解法很简单，用一个数组模拟哈希集合，很容易找到 `nums` 中那些没有出现的元素。

非要优化空间复杂度也简单，说白了就是用输入数组 `nums` 本身作为哈希集合。只要你做了 [✨442. 数组中重复的数据](/problems/find-all-duplicates-in-an-array/)，不难想到这道题也有不用额外的存储空间的解法。

因为题目说 `nums` 中的元素取值都在 `[1, n]` 之间，所以在 `[0, n-1]` 之间，即元素本身就和索引可以形成一一映射关系，所以可以用 `nums` 本身模拟哈希集合的效果，可以参考这篇文章 [如何寻找缺失和重复的元素](https://labuladong.online/algo/frequency-interview/mismatch-set/)。

我们给 `nums` 中所有元素对应的索引做标记，那么最终缺失的那些元素对应的索引就不会被标记，我们也就可以把缺失的那些元素找出来。

> 注意：用乘 -1 的方式给索引做标记的前提是，`nums` 中的元素都为正数，不能包含 0，否则无法区分该索引是否被标记。

**详细题解**：
  - [【练习】哈希表更多习题](https://labuladong.online/algo/problem-set/hash-table/)

</div>





<div id="solution">

## 解法代码



<div class="tab-panel"><div class="tab-nav">
<button data-tab-item="cpp" class="tab-nav-button btn " data-tab-group="default" onclick="switchTab(this)">cpp🤖</button>

<button data-tab-item="python" class="tab-nav-button btn " data-tab-group="default" onclick="switchTab(this)">python🤖</button>

<button data-tab-item="java" class="tab-nav-button btn active" data-tab-group="default" onclick="switchTab(this)">java🟢</button>

<button data-tab-item="go" class="tab-nav-button btn " data-tab-group="default" onclick="switchTab(this)">go🤖</button>

<button data-tab-item="javascript" class="tab-nav-button btn " data-tab-group="default" onclick="switchTab(this)">javascript🤖</button>
</div><div class="tab-content">
<div data-tab-item="cpp" class="tab-item " data-tab-group="default"><div class="highlight">

```cpp
// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

#include <vector>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> count(n + 1, 0);
        for (int num : nums) {
            count[num]++;
        }
        std::vector<int> res;
        for (int num = 1; num <= n; num++) {
            if (count[num] == 0) {
                res.push_back(num);
            }
        }
        return res;
    }
};

class Solution2 {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        for (int num : nums) {
            // 注意索引，nums 中元素大小从 1 开始，
            // 而索引是从 0 开始的，所以有一位索引偏移
            int index = abs(num) - 1;
            if (nums[index] > 0) {
                // 把索引 num - 1 置为负数
                nums[index] = -nums[index];
            } else {
                // 之前已经把对应索引的元素变成负数了，
                // 这说明 num 重复出现了两次，但我们什么都不用做，让索引继续保持负数
                // (No action needed here, so no code change, just keeping the comments.)
            }
        }

        std::vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                // 说明没有元素和这个索引对应，即找到一个缺失元素
                res.push_back(i + 1);
            }
        }

        return res;
    }
};
```

</div></div>

<div data-tab-item="python" class="tab-item " data-tab-group="default"><div class="highlight">

```python
# 注意：python 代码由 chatGPT🤖 根据我的 java 代码翻译。
# 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        count = [0] * (n + 1)
        for num in nums:
            count[num] += 1
        res = []
        for num in range(1, n + 1):
            if count[num] == 0:
                res.append(num)
        return res


class Solution2:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        for num in nums:
            # 注意索引，nums 中元素大小从 1 开始，
            # 而索引是从 0 开始的，所以有一位索引偏移
            if nums[abs(num) - 1] < 0:
                # 之前已经把对应索引的元素变成负数了，
                # 这说明 num 重复出现了两次，但我们什么都不用做，让索引继续保持负数
                pass
            else:
                # 把索引 num - 1 置为负数
                nums[abs(num) - 1] *= -1

        res = []
        for i in range(len(nums)):
            if nums[i] > 0:
                # 说明没有元素和这个索引对应，即找到一个缺失元素
                res.append(i + 1)
        return res
```

</div></div>

<div data-tab-item="java" class="tab-item active" data-tab-group="default"><div class="highlight">

```java
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int n = nums.length;
        int[] count = new int[n + 1];
        for (int num : nums) {
            count[num]++;
        }
        List<Integer> res = new LinkedList<>();
        for (int num = 1; num <= n; num++) {
            if (count[num] == 0) {
                res.add(num);
            }
        }
        return res;
    }
}


class Solution2 {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        for (int num : nums) {
            // 注意索引，nums 中元素大小从 1 开始，
            // 而索引是从 0 开始的，所以有一位索引偏移
            if (nums[Math.abs(num) - 1] < 0) {
                // 之前已经把对应索引的元素变成负数了，
                // 这说明 num 重复出现了两次，但我们什么都不用做，让索引继续保持负数
            } else {
                // 把索引 num - 1 置为负数
                nums[Math.abs(num) - 1] *= -1;
            }
        }

        List<Integer> res = new LinkedList<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > 0) {
                // 说明没有元素和这个索引对应，即找到一个缺失元素
                res.add(i + 1);
            }
        }

        return res;
    }
}
```

</div></div>

<div data-tab-item="go" class="tab-item " data-tab-group="default"><div class="highlight">

```go
// 注意：go 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

func findDisappearedNumbers(nums []int) []int {
    n := len(nums)
    count := make([]int, n+1)
    for _, num := range nums {
        count[num]++
    }
    res := []int{}
    for num := 1; num <= n; num++ {
        if count[num] == 0 {
            res = append(res, num)
        }
    }
    return res
}

func findDisappearedNumbers2(nums []int) []int {
    for _, num := range nums {
        // 注意索引，nums 中元素大小从 1 开始，
        // 而索引是从 0 开始的，所以有一位索引偏移
        if nums[abs(num)-1] < 0 {
            // 之前已经把对应索引的元素变成负数了，
            // 这说明 num 重复出现了两次，但我们什么都不用做，让索引继续保持负数
        } else {
            // 把索引 num - 1 置为负数
            nums[abs(num)-1] *= -1
        }
    }

    res := []int{}
    for i := 0; i < len(nums); i++ {
        if nums[i] > 0 {
            // 说明没有元素和这个索引对应，即找到一个缺失元素
            res = append(res, i+1)
        }
    }

    return res
}

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}
```

</div></div>

<div data-tab-item="javascript" class="tab-item " data-tab-group="default"><div class="highlight">

```javascript
// 注意：javascript 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

var findDisappearedNumbers = function(nums) {
    let n = nums.length;
    let count = new Array(n + 1).fill(0);
    for (let num of nums) {
        count[num]++;
    }
    let res = [];
    for (let num = 1; num <= n; num++) {
        if (count[num] === 0) {
            res.push(num);
        }
    }
    return res;
};

var findDisappearedNumbers2 = function(nums) {
    for (let num of nums) {
        // 注意索引，nums 中元素大小从 1 开始，
        // 而索引是从 0 开始的，所以有一位索引偏移
        let index = Math.abs(num) - 1;
        if (nums[index] < 0) {
            // 之前已经把对应索引的元素变成负数了，
            // 这说明 num 重复出现了两次，但我们什么都不用做，让索引继续保持负数
        } else {
            // 把索引 num - 1 置为负数
            nums[index] *= -1;
        }
    }

    let res = [];
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] > 0) {
            // 说明没有元素和这个索引对应，即找到一个缺失元素
            res.push(i + 1);
        }
    }

    return res;
};
```

</div></div>
</div></div>

<hr /><details open hint-container details><summary style="font-size: medium"><strong>🌟🌟 算法可视化 🌟🌟</strong></summary><div id="data_find-all-numbers-disappeared-in-an-array"  category="leetcode" ></div><div class="resizable aspect-ratio-container" style="height: 100%;">
<div id="iframe_find-all-numbers-disappeared-in-an-array"></div></div>
</details><hr /><br />

</div>
</details>
</div>

