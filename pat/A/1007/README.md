# 1007 Maximum Subsequence Sum （25 分）
Given a sequence of K integers { N<sub>1</sub>,N<sub>2</sub>, ..., N<sub>​K</sub>}. A continuous subsequence is defined to be { N<sub>i</sub>,N<sub>i+1</sub>, ..., N<sub>j</sub>} where 1≤i≤j≤K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

## Input Specification:
Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (≤10000). The second line contains K numbers, separated by a space.

## Output Specification:
For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

## Sample Input:
>10
>
>-10 1 2 3 4 -5 -23 3 7 -21
## Sample Output:
>10 1 4

URL:https://pintia.cn/problem-sets/994805342720868352/problems/994805514284679168
# 心得
1. 容易被忽略的输出顺序
一开始我是没有拿到满分的，因为我忘记了当存在多个相同的最小值的时候，应该输出使i和j最小的那个。同时，当整个序列全部都为负数
的时候，max=0。因此存在一个特殊情况：整个序列都是非正数，同时第一个数为0。那么这时候，虽然max=0，但不能输出序列头和序列尾
了事，而需要根据具体那个和一样等于0，但ij最小的子序列来判定了（其实就是0,0）。(before，我也不知道自己表达的是什么意思= =)

2. 对于上面，输出顺序可以依靠sum < max来控制。同时，当max==0的时候，表示的是虽然序列里大部分是负数，但仍然有使和等于0的子序列存在（一般都是n个0），因此这时候要和max为正数一样看待；同时，当max<0，则表示没有比无定义的子序列（即(0,0)，表示这个子序列什么都没有）更大的子序列，此时则应该按照题目要求，输出数列的首尾。