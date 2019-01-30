# 1009 Product of Polynomials （25 分）
this time, you are supposed to find A×B where A and B are two polynomials.

## Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

K N<sub>1</sub> a<sub>N​1</sub> N<sub>2</sub> a<sub>N2</sub> ... N<sub>K</sub> a<sub>​NK</sub>
​​
where K is the number of nonzero terms in the polynomial, N<sub>i</sub> and a<sub>N<sub>i</sub></sub>(i=1,2,⋯,K) are the exponents and coefficients, respectively. It is given that 1≤K≤10, 0≤N<sub>K</sub><⋯<N<sub>2</sub><N<sub>1</sub>≤1000.

## Output Specification:
For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

## Sample Input:
>2 1 2.4 0 3.2
>
>2 2 1.5 1 0.5

## Sample Output:
>3 3 3.6 2 6.0 1 1.6

# 心得
1、选好数据结构很关键。这次我选了链表+一维数组，一维数组作为链表查找的索引，然后链表有两种插入方式，一种是插入到尾部，一种是按顺序插入，除了按顺序插入之外，其他操作的复杂度都是O(1)。

2、C++的格式化十分麻烦
