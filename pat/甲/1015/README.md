# 1015 Reversible Primes （20 分）
A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (<10<sup>5</sup>) and D (1<D≤10), you are supposed to tell if N is a reversible prime with radix D.

## Input Specification:
The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

## Output Specification:
For each test case, print in one line Yes if N is a reversible prime with radix D, or No if not.

## Sample Input:

>73 10
>
>23 2
>
>23 10
>
>-2

## Sample Output:

>Yes
>
>Yes
>
>No

# 心得与体会
这题一开始写，逻辑是没有问题的，但错了一个测试点，这是因为我的质数判断写错了= =。

质数判断的时候，里层循环的循环条件应该是i×i<=j，其中i为从2开始循环的数，j为判断是否为质数的数。

另一方面，0、1不是质数。

同时，有一点可以尝试改进的是，以后可以考虑采用普通数组来存储某个进制的数，而不采用转换麻烦的字符串。
字符串除了输入输出有优势外，转换起来十分麻烦。
做法参考https://blog.csdn.net/yyecust/article/details/54605097 。