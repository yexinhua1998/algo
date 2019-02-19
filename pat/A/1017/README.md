# 1017 Queueing at Bank （25 分）
Suppose a bank has K windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. All the customers have to wait in line behind the yellow line, until it is his/her turn to be served and there is a window available. It is assumed that no window can be occupied by a single customer for more than 1 hour.

Now given the arriving time T and the processing time P of each customer, you are supposed to tell the average waiting time of all the customers.

## Input Specification:
Each input file contains one test case. For each case, the first line contains 2 numbers: N (≤10<sup>4</sup>) - the total number of customers, and K (≤100) - the number of windows. Then N lines follow, each contains 2 times: HH:MM:SS - the arriving time, and P - the processing time in minutes of a customer. Here HH is in the range [00, 23], MM and SS are both in [00, 59]. It is assumed that no two customers arrives at the same time.

Notice that the bank opens from 08:00 to 17:00. Anyone arrives early will have to wait in line till 08:00, and anyone comes too late (at or after 17:00:01) will not be served nor counted into the average.

## Output Specification:
For each test case, print in one line the average waiting time of all the customers, in minutes and accurate up to 1 decimal place.

## Sample Input:
>7 3
>
>07:55:00 16
>
>17:00:01 2
>
>07:59:59 15
>
>08:01:00 60
>
>08:00:00 30
>
>08:00:02 2
>
>08:03:00 10

## Sample Output:
>8.2

# 心得与体会
1. 模拟题需要认真和细心，需要头脑里对整个事情有一个模拟，心里要想好每一种情况进入你的程序中控制流应该是怎么走。
2. 一般而言，时间模拟类，最好now在最后++。先处理现在的东西，然后让时间过去
3. 模拟题一般不怕超时，性能和可读性/可维护性/可靠性选择后者。
4. 细心细心细心，仔细仔细仔细。