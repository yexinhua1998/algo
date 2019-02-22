# 1021 Deepest Root （25 分）
A graph which is connected and acyclic can be considered a tree. The hight of the tree depends on the selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called the deepest root.

## Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (≤10<sup>4</sup>​​) which is the number of nodes, and hence the nodes are numbered from 1 to N. Then N−1 lines follow, each describes an edge by given the two adjacent nodes' numbers.

## Output Specification:
For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their numbers. In case that the given graph is not a tree, print Error: K components where K is the number of connected components in the graph.

## Sample Input 1:
>5
>
>1 2
>
>1 3
>
>1 4
>
>2 5

## Sample Output 1:
>3
>
>4
>
>5

## Sample Input 2:
>5
>
>1 3
>
>1 4
>
>2 5
>
>3 4

## Sample Output 2:
>Error: 2 components

# 心得与体会
1. 要看清楚题目的性能要求。比如这类型的水题，给足了2000ms的时间，可以直接暴力搜索。
2. 用STL可以减少自己构造基础数据结构的时间，加快做题速度。