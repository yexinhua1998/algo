# 1010 Radix （25 分）
Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is yes, if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N
<sub>​1</sub>
​​  and N
​<sub>2</sub>
​​ , your task is to find the radix of one number while that of the other is given.

## Input Specification:
Each input file contains one test case. Each case occupies a line which contains 4 positive integers:

>N1 N2 tag radix

Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set { 0-9, a-z } where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number radix is the radix of N1 if tag is 1, or of N2 if tag is 2.

## Output Specification:
For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print Impossible. If the solution is not unique, output the smallest possible radix.

## Sample Input 1:

>6 110 1 10

## Sample Output 1:
>2

## Sample Input 2:
>1 ab 1 2

## Sample Output 2:
>Impossible

# 心得
比起之前的题目，这一题是比较难的

1、数据类型的选择。由于考虑到表示的数可能会很大，比如表示36进制的zzzzzzzzzz，因此选用了unsigned long long作为部分整形数字的类型。

2、边界。最开始我以为进制的上界是36，因为最大可以表示的是z，z是35，那么最大进制就是36。但后来发现错了，之后就尝试不设上限，让算法一直往上遍历。这时测试点7就会超时。后来参考了别人的博客，才发现原来是有上界的，上界就是已知进制的数的值+1。

3、查找方法。查找结果的方式决定了算法的效率。刚开始我是直接for这样轮下去的，后来测试点7出现了问题，才参考CSDN，发现用二分法查找会快很多。

# 参考
CSDN：https://www.cnblogs.com/weedboy/p/7244819.html
