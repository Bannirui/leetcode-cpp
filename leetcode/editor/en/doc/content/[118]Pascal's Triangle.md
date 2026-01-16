<p>Given an integer <code>numRows</code>, return the first numRows of <strong>Pascal's triangle</strong>.</p>

<p>In <strong>Pascal's triangle</strong>, each number is the sum of the two numbers directly above it as shown:</p> 
<img alt="" src="https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif" style="height:240px; width:260px" /> 
<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p> 
<pre><strong>Input:</strong> numRows = 5
<strong>Output:</strong> [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
</pre>
<p><strong class="example">Example 2:</strong></p> 
<pre><strong>Input:</strong> numRows = 1
<strong>Output:</strong> [[1]]
</pre> 
<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= numRows &lt;= 30</code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>Array | Dynamic Programming</details><br>

<div>👍 14745, 👎 559<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/issues' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.online/algo/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.online/algo/' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>

<div id="labuladong"><hr>

**通知：为满足广大读者的需求，网站上架 [速成目录](https://labuladong.online/algo/intro/quick-learning-plan/)，如有需要可以看下，谢谢大家的支持~**

<details><summary><strong>labuladong 思路</strong></summary>


<div id="labuladong_solution_zh">

## 基本思路

这题很简单，不过我提供两个版本的解法，一个是迭代的方式，一个是递归的方式，具体思路看注释。

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

// 迭代方式
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows < 1) {
            return res;
        }
        // 先把第一层装进去作为 base case
        vector<int> firstRow = {1};
        res.push_back(firstRow);
        // 开始一层一层生成，装入 res
        for (int i = 2; i <= numRows; i++) {
            vector<int> prevRow = res.back();
            res.push_back(generateNextRow(prevRow));
        }
        return res;
    }

private:
    // 输入上一层的元素，生成并返回下一层的元素
    vector<int> generateNextRow(const vector<int>& prevRow) {
        vector<int> curRow;
        curRow.push_back(1);
        for (size_t i = 0; i < prevRow.size() - 1; i++) {
            curRow.push_back(prevRow[i] + prevRow[i + 1]);
        }
        curRow.push_back(1);
        return curRow;
    }
};

// 递归方式
class Solution2 {
public:
    // 定义：输入 numRows，返回行数为 numRows 的杨辉三角
    vector<vector<int>> generate(int numRows) {
        // 递归的 base case
        if (numRows == 1) {
            vector<vector<int>> triangle = {{1}};
            return triangle;
        }

        // 先递归生成高度为 numRows - 1 的杨辉三角
        vector<vector<int>> triangle = generate(numRows - 1);

        // 根据最底层元素生成一行新元素
        vector<int> bottomRow = triangle.back();
        vector<int> newRow;
        newRow.push_back(1);
        for (size_t i = 0; i < bottomRow.size() - 1; i++) {
            newRow.push_back(bottomRow[i] + bottomRow[i + 1]);
        }
        newRow.push_back(1);
        // 把新的一行放到杨辉三角底部
        triangle.push_back(newRow);

        return triangle;
    }
};
```

</div></div>

<div data-tab-item="python" class="tab-item " data-tab-group="default"><div class="highlight">

```python
# 注意：python 代码由 chatGPT🤖 根据我的 java 代码翻译。
# 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

# 迭代方式
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = []
        if numRows < 1:
            return res
        # 先把第一层装进去作为 base case
        firstRow = [1]
        res.append(firstRow)
        # 开始一层一层生成，装入 res
        for i in range(2, numRows + 1):
            prevRow = res[-1]
            res.append(self.generateNextRow(prevRow))
        return res

    # 输入上一层的元素，生成并返回下一层的元素
    def generateNextRow(self, prevRow: List[int]) -> List[int]:
        curRow = [1]
        for i in range(len(prevRow) - 1):
            curRow.append(prevRow[i] + prevRow[i + 1])
        curRow.append(1)
        return curRow

# 递归方式
class Solution2:
    # 定义：输入 numRows，返回行数为 numRows 的杨辉三角
    def generate(self, numRows: int) -> List[List[int]]:
        # 递归的 base case
        if numRows == 1:
            triangle = []
            # 先把第一层装进去作为 base case
            firstRow = [1]
            triangle.append(firstRow)
            return triangle

        # 先递归生成高度为 numRows - 1 的杨辉三角
        triangle = self.generate(numRows - 1)

        # 根据最底层元素生成一行新元素
        bottomRow = triangle[-1]
        newRow = [1]
        for i in range(len(bottomRow) - 1):
            newRow.append(bottomRow[i] + bottomRow[i + 1])
        newRow.append(1)
        # 把新的一行放到杨辉三角底部
        triangle.append(newRow)

        return triangle
```

</div></div>

<div data-tab-item="java" class="tab-item active" data-tab-group="default"><div class="highlight">

```java
// 迭代方式
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>();
        if (numRows < 1) {
            return res;
        }
        // 先把第一层装进去作为 base case
        List<Integer> firstRow = new ArrayList<>();
        firstRow.add(1);
        res.add(firstRow);
        // 开始一层一层生成，装入 res
        for (int i = 2; i <= numRows; i++) {
            List<Integer> prevRow = res.get(res.size() - 1);
            res.add(generateNextRow(prevRow));
        }
        return res;
    }

    // 输入上一层的元素，生成并返回下一层的元素
    List<Integer> generateNextRow(List<Integer> prevRow) {
        List<Integer> curRow = new ArrayList<>();
        curRow.add(1);
        for (int i = 0; i < prevRow.size() - 1; i++) {
            curRow.add(prevRow.get(i) + prevRow.get(i + 1));
        }
        curRow.add(1);
        return curRow;
    }
}

// 递归方式
class Solution2 {
    // 定义：输入 numRows，返回行数为 numRows 的杨辉三角
    public List<List<Integer>> generate(int numRows) {
        // 递归的 base case
        if (numRows == 1) {
            List<List<Integer>> triangle = new ArrayList<>();
            // 先把第一层装进去作为 base case
            List<Integer> firstRow = new ArrayList<>();
            firstRow.add(1);
            triangle.add(firstRow);
            return triangle;
        }

        // 先递归生成高度为 numRows - 1 的杨辉三角
        List<List<Integer>> triangle = generate(numRows - 1);

        // 根据最底层元素生成一行新元素
        List<Integer> bottomRow = triangle.get(triangle.size() - 1);
        List<Integer> newRow = new ArrayList<>();
        newRow.add(1);
        for (int i = 0; i < bottomRow.size() - 1; i++) {
            newRow.add(bottomRow.get(i) + bottomRow.get(i + 1));
        }
        newRow.add(1);
        // 把新的一行放到杨辉三角底部
        triangle.add(newRow);

        return triangle;
    }
}
```

</div></div>

<div data-tab-item="go" class="tab-item " data-tab-group="default"><div class="highlight">

```go
// 注意：go 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

// 迭代方式
func generate(numRows int) [][]int {
    var res [][]int
    if numRows < 1 {
        return res
    }
    // 先把第一层装进去作为 base case
    firstRow := []int{1}
    res = append(res, firstRow)
    // 开始一层一层生成，装入 res
    for i := 2; i <= numRows; i++ {
        prevRow := res[len(res)-1]
        res = append(res, generateNextRow(prevRow))
    }
    return res
}

// 输入上一层的元素，生成并返回下一层的元素
func generateNextRow(prevRow []int) []int {
    curRow := []int{1}
    for i := 0; i < len(prevRow)-1; i++ {
        curRow = append(curRow, prevRow[i]+prevRow[i+1])
    }
    curRow = append(curRow, 1)
    return curRow
}

// 递归方式
// 定义：输入 numRows，返回行数为 numRows 的杨辉三角
func generateRecursive(numRows int) [][]int {
    // 递归的 base case
    if numRows == 1 {
        triangle := [][]int{}
        // 先把第一层装进去作为 base case
        firstRow := []int{1}
        triangle = append(triangle, firstRow)
        return triangle
    }

    // 先递归生成高度为 numRows - 1 的杨辉三角
    triangle := generateRecursive(numRows - 1)

    // 根据最底层元素生成一行新元素
    bottomRow := triangle[len(triangle)-1]
    newRow := []int{1}
    for i := 0; i < len(bottomRow)-1; i++ {
        newRow = append(newRow, bottomRow[i]+bottomRow[i+1])
    }
    newRow = append(newRow, 1)
    // 把新的一行放到杨辉三角底部
    triangle = append(triangle, newRow)

    return triangle
}
```

</div></div>

<div data-tab-item="javascript" class="tab-item " data-tab-group="default"><div class="highlight">

```javascript
// 注意：javascript 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

// 迭代方式
var generate = function(numRows) {
    var res = [];
    if (numRows < 1) {
        return res;
    }
    // 先把第一层装进去作为 base case
    var firstRow = [1];
    res.push(firstRow);
    // 开始一层一层生成，装入 res
    for (var i = 2; i <= numRows; i++) {
        var prevRow = res[res.length - 1];
        res.push(generateNextRow(prevRow));
    }
    return res;
};

// 输入上一层的元素，生成并返回下一层的元素
function generateNextRow(prevRow) {
    var curRow = [1];
    for (var i = 0; i < prevRow.length - 1; i++) {
        curRow.push(prevRow[i] + prevRow[i + 1]);
    }
    curRow.push(1);
    return curRow;
}

// 递归方式
// 定义：输入 numRows，返回行数为 numRows 的杨辉三角
var generate2 = function(numRows) {
    // 递归的 base case
    if (numRows === 1) {
        var triangle = [];
        // 先把第一层装进去作为 base case
        var firstRow = [1];
        triangle.push(firstRow);
        return triangle;
    }

    // 先递归生成高度为 numRows - 1 的杨辉三角
    var triangle = generate2(numRows - 1);

    // 根据最底层元素生成一行新元素
    var bottomRow = triangle[triangle.length - 1];
    var newRow = [1];
    for (var i = 0; i < bottomRow.length - 1; i++) {
        newRow.push(bottomRow[i] + bottomRow[i + 1]);
    }
    newRow.push(1);
    // 把新的一行放到杨辉三角底部
    triangle.push(newRow);

    return triangle;
};
```

</div></div>
</div></div>

<hr /><details open hint-container details><summary style="font-size: medium"><strong>🍭🍭 算法可视化 🍭🍭</strong></summary><div id="data_pascals-triangle"  category="leetcode" ></div><div class="resizable aspect-ratio-container" style="height: 100%;">
<div id="iframe_pascals-triangle"></div></div>
</details><hr /><br />

</div>
</details>
</div>

