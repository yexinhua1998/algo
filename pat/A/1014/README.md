# 1014 Waiting in Line (30 分)
Suppose a bank has *N* windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. The rules for the customers to wait in line are:

* The space inside the yellow line in front of each window is enough to contain a line with M customers. Hence when all the N lines are full, all the customers after (and including) the (NM+1)st one will have to wait in a line behind the yellow line.
* Each customer will choose the shortest line to wait in when crossing the yellow line. If there are two or more lines with the same length, the customer will always choose the window with the smallest number.
* Customer<sub>​i</sub> will take T<sub>i</sub> minutes to have his/her transaction processed.
* The first *N* customers are assumed to be served at 8:00am.
Now given the processing time of each customer, you are supposed to tell the exact time at which a customer has his/her business done.

For example, suppose that a bank has 2 windows and each window may have 2 custmers waiting inside the yellow line. There are 5 customers waiting with transactions taking 1, 2, 6, 4 and 3 minutes, respectively. At 08:00 in the morning, customer<sub>1</sub> is served at window<sub>1</sub> while customer<sub>2</sub> is served at window<sub>2</sub>. Customer<sub>3</sub> will wait in front of window<sub>1</sub> and customer<sub>4</sub> will wait in front of window<sub>2</sub>. Customer<sub>5</sub> will wait behind the yellow line.

At 08:01, customer<sub>1</sub> is done and customer<sub>5</sub> enters the line in front of window<sub>1</sub> since that line seems shorter now. Customer<sub>2</sub> will leave at 08:02, customer<sub>4</sub> at 08:06, customer<sub>3</sub> at 08:07, and finally customer<sub>5</sub> at 08:10.

## Input Specification:
Each input file contains one test case. Each case starts with a line containing 4 positive integers: *N* (≤20, number of windows), *M* (≤10, the maximum capacity of each line inside the yellow line), *K* (≤1000, number of customers), and *Q* (≤1000, number of customer queries).

The next line contains *K* positive integers, which are the processing time of the *K* customers.

The last line contains *Q* positive integers, which represent the customers who are asking about the time they can have their transactions done. The customers are numbered from 1 to *K*.

## Output Specification:
For each of the *Q* customers, print in one line the time at which his/her transaction is finished, in the format HH:MM where HH is in [08, 17] and MM is in [00, 59]. Note that since the bank is closed everyday after 17:00, for those customers who cannot be served before 17:00, you must output Sorry instead.

## Sample Input:

>2 2 7 5
>
>1 2 6 4 3 534 2
>
>3 4 5 6 7

## Sample Output:

>08:07
>
>08:06
>
>08:10
>
>17:00
>
>Sorry

# 心得与体会
这是一道模拟题，主要是模拟银行的排队情况。

1. 题目有很多细节，读题时需要非常非常小心和认真。像这次一开始没有完全理解题意就开始做，导致一波三折
2. 模拟尽量对细节更加还原。大部分大神采用了一秒一秒地加的方法，我也不知道为什么。我采用的是比较快一丁点的方法，但调试会比前面大神的方法更加复杂，容易出问题很多。
3. 模拟题还是挺难的/滑稽