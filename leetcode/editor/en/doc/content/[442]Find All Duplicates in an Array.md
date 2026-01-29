<p>Given an integer array <code>nums</code> of length <code>n</code> where all the integers of <code>nums</code> are in the range <code>[1, n]</code> and each integer appears <strong>at most</strong> <strong>twice</strong>, return <em>an array of all the integers that appears <strong>twice</strong></em>.</p>

<p>You must write an algorithm that runs in <code>O(n)</code> time and uses only <em>constant</em> auxiliary space, excluding the space needed to store the output</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<pre><strong>Input:</strong> nums = [4,3,2,7,8,2,3,1]
<strong>Output:</strong> [2,3]
</pre>
<p><strong class="example">Example 2:</strong></p> 
<pre><strong>Input:</strong> nums = [1,1,2]
<strong>Output:</strong> [1]
</pre>
<p><strong class="example">Example 3:</strong></p> 
<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> []
</pre> 
<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>n == nums.length</code></li> 
 <li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li> 
 <li><code>1 &lt;= nums[i] &lt;= n</code></li> 
 <li>Each element in <code>nums</code> appears <strong>once</strong> or <strong>twice</strong>.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>Array | Hash Table | Sorting</details><br>

<div>👍 11069, 👎 442<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/issues' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.online/algo/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.online/algo/' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>

<div id="labuladong"><hr>

**通知：为满足广大读者的需求，网站上架 [速成目录](https://labuladong.online/algo/intro/quick-learning-plan/)，如有需要可以看下，谢谢大家的支持~**

<details><summary><strong>labuladong 思路</strong></summary>


<div id="labuladong_solution_zh">

## 基本思路

这道题就用常规的解法做吧，用哈希集合很容易找到 `nums` 中那些重复的元素。

不用额外的存储空间的解法我也写了，因为题目说 `nums` 中的元素取值都在 `[1, n]` 之间，即元素本身就和索引成映射关系，所以可以用 `nums` 本身模拟哈希集合的效果，详解你可以看下 [如何寻找缺失和重复的元素](https://labuladong.online/algo/frequency-interview/mismatch-set/)。

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
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        // 用数组模拟哈希集合
        vector<int> seen(n + 1, 0);
        for (int num : nums) {
            if (seen[num] == 0) {
                // 添加到哈希集合
                seen[num] = 1;
            } else {
                // 找到重复元素
                res.push_back(num);
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int num : nums) {
            // 注意索引，nums 中元素大小从 1 开始，
            // 而索引是从 0 开始的，所以有一位索引偏移
            if (nums[abs(num) - 1] < 0) {
                // 之前已经把对应索引的元素变成负数了，
                // 这说明 num 重复出现了两次
                res.push_back(abs(num));
            } else {
                // 把索引 num - 1 置为负数
                nums[abs(num) - 1] *= -1;
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
    def findDuplicates(self, nums):
        n = len(nums)
        res = []
        # 用数组模拟哈希集合
        seen = [0] * (n + 1)
        for num in nums:
            if seen[num] == 0:
                # 添加到哈希集合
                seen[num] = 1
            else:
                # 找到重复元素
                res.append(num)
        return res

class Solution2:
    def findDuplicates(self, nums):
        res = []
        for num in nums:
            # 注意索引，nums 中元素大小从 1 开始，
            # 而索引是从 0 开始的，所以有一位索引偏移
            if nums[abs(num) - 1] < 0:
                # 之前已经把对应索引的元素变成负数了，
                # 这说明 num 重复出现了两次
                res.append(abs(num))
            else:
                # 把索引 num - 1 置为负数
                nums[abs(num) - 1] *= -1

        return res
```

</div></div>

<div data-tab-item="java" class="tab-item active" data-tab-group="default"><div class="highlight">

```java
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        int n = nums.length;
        List<Integer> res = new LinkedList<>();
        // 用数组模拟哈希集合
        int[] seen = new int[n + 1];
        for (int num : nums) {
            if (seen[num] == 0) {
                // 添加到哈希集合
                seen[num] = 1;
            } else {
                // 找到重复元素
                res.add(num);
            }
        }
        return res;
    }
}

class Solution2 {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> res = new LinkedList<>();
        for (int num : nums) {
            // 注意索引，nums 中元素大小从 1 开始，
            // 而索引是从 0 开始的，所以有一位索引偏移
            if (nums[Math.abs(num) - 1] < 0) {
                // 之前已经把对应索引的元素变成负数了，
                // 这说明 num 重复出现了两次
                res.add(Math.abs(num));
            } else {
                // 把索引 num - 1 置为负数
                nums[Math.abs(num) - 1] *= -1;
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

func findDuplicates(nums []int) []int {
    n := len(nums)
    res := make([]int, 0)
    // 用数组模拟哈希集合
    seen := make([]int, n+1)
    for _, num := range nums {
        if seen[num] == 0 {
            // 添加到哈希集合
            seen[num] = 1
        } else {
            // 找到重复元素
            res = append(res, num)
        }
    }
    return res
}

func findDuplicates2(nums []int) []int {
    res := make([]int, 0)
    for _, num := range nums {
        // 注意索引，nums 中元素大小从 1 开始，
        // 而索引是从 0 开始的，所以有一位索引偏移
        index := abs(num) - 1
        if nums[index] < 0 {
            // 之前已经把对应索引的元素变成负数了，
            // 这说明 num 重复出现了两次
            res = append(res, abs(num))
        } else {
            // 把索引 num - 1 置为负数
            nums[index] *= -1
        }
    }
    return res
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}
```

</div></div>

<div data-tab-item="javascript" class="tab-item " data-tab-group="default"><div class="highlight">

```javascript
// 注意：javascript 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

var findDuplicates = function(nums) {
    let n = nums.length;
    let res = [];
    // 用数组模拟哈希集合
    let seen = Array(n + 1).fill(0);
    for (let num of nums) {
        if (seen[num] === 0) {
            // 添加到哈希集合
            seen[num] = 1;
        } else {
            // 找到重复元素
            res.push(num);
        }
    }
    return res;
};

var findDuplicates2 = function(nums) {
    let res = [];
    for (let num of nums) {
        // 注意索引，nums 中元素大小从 1 开始，
        // 而索引是从 0 开始的，所以有一位索引偏移
        if (nums[Math.abs(num) - 1] < 0) {
            // 之前已经把对应索引的元素变成负数了，
            // 这说明 num 重复出现了两次
            res.push(Math.abs(num));
        } else {
            // 把索引 num - 1 置为负数
            nums[Math.abs(num) - 1] *= -1;
        }
    }

    return res;
};
```

</div></div>
</div></div>

<hr /><details open hint-container details><summary style="font-size: medium"><strong>🥳🥳 算法可视化 🥳🥳</strong></summary><div id="data_find-all-duplicates-in-an-array"  category="leetcode" ></div><div class="resizable aspect-ratio-container" style="height: 100%;">
<div id="iframe_find-all-duplicates-in-an-array"></div></div>
</details><hr /><br />

</div>
</details>
</div>

