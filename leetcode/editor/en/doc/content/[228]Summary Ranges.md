<p>You are given a <strong>sorted unique</strong> integer array <code>nums</code>.</p>

<p>A <strong>range</strong> <code>[a,b]</code> is the set of all integers from <code>a</code> to <code>b</code> (inclusive).</p>

<p>Return <em>the <strong>smallest sorted</strong> list of ranges that <strong>cover all the numbers in the array exactly</strong></em>. That is, each element of <code>nums</code> is covered by exactly one of the ranges, and there is no integer <code>x</code> such that <code>x</code> is in one of the ranges but not in <code>nums</code>.</p>

<p>Each range <code>[a,b]</code> in the list should be output as:</p>

<ul> 
 <li><code>"a-&gt;b"</code> if <code>a != b</code></li> 
 <li><code>"a"</code> if <code>a == b</code></li> 
</ul>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,1,2,4,5,7]
<strong>Output:</strong> ["0-&gt;2","4-&gt;5","7"]
<strong>Explanation:</strong> The ranges are:
[0,2] --&gt; "0-&gt;2"
[4,5] --&gt; "4-&gt;5"
[7,7] --&gt; "7"
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,2,3,4,6,8,9]
<strong>Output:</strong> ["0","2-&gt;4","6","8-&gt;9"]
<strong>Explanation:</strong> The ranges are:
[0,0] --&gt; "0"
[2,4] --&gt; "2-&gt;4"
[6,6] --&gt; "6"
[8,9] --&gt; "8-&gt;9"
</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>0 &lt;= nums.length &lt;= 20</code></li> 
 <li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li> 
 <li>All the values of <code>nums</code> are <strong>unique</strong>.</li> 
 <li><code>nums</code> is sorted in ascending order.</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>Array</details><br>

<div>👍 4480, 👎 2365<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/issues' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.online/algo/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.online/algo/' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>

<div id="labuladong"><hr>

**通知：为满足广大读者的需求，网站上架 [速成目录](https://labuladong.online/algo/intro/quick-learning-plan/)，如有需要可以看下，谢谢大家的支持~**

</div>

