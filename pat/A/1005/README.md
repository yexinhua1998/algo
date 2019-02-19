# 1005 Spell It Right （20 分）
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (≤10^100).

Output Specification:
For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345
Sample Output:
one five

URL:https://pintia.cn/problem-sets/994805342720868352/problems/994805519074574336

## 一些心得
# 1、根据数据规模，来确定常量N
本题中给定了N<=10^100，当以字符串输入的时候，字符串的长度最长为101（输入为10^100的时候）。因此字符串的长度常量应该为102。
# 2、特殊情况
本题中有一个特殊情况就是输入0，这个时候要特别小心。如果输入为0，需要特别分开，并给出zero。