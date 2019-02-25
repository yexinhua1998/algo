
# 1022 Digital Library （30 分）
A Digital Library contains millions of books, stored according to their titles, authors, key words of their abstracts, publishers, and published years. Each book is assigned an unique 7-digit number as its ID. Given any query from a reader, you are supposed to output the resulting books, sorted in increasing order of their ID's.

## Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (≤10<sup>4</sup>) which is the total number of books. Then N blocks follow, each contains the information of a book in 6 lines:


Line #1: the 7-digit ID number;

Line #2: the book title -- a string of no more than 80 characters;

Line #3: the author -- a string of no more than 80 characters;

Line #4: the key words -- each word is a string of no more than 10 characters without any white space, and the keywords are separated by exactly one space;

Line #5: the publisher -- a string of no more than 80 characters;

Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].

It is assumed that each book belongs to one author only, and contains no more than 5 key words; there are no more than 1000 distinct key words in total; and there are no more than 1000 distinct publishers.


After the book information, there is a line containing a positive integer M (≤1000) which is the number of user's search queries. Then M lines follow, each in one of the formats shown below:


1: a book title

2: name of an author

3: a key word

4: name of a publisher

5: a 4-digit number representing the year

## Output Specification:
For each query, first print the original query in a line, then output the resulting book ID's in increasing order, each occupying a line. If no book is found, print Not Found instead.

## Sample Input:
>3
>
>1111111
>
>The Testing Book
>
>Yue Chen
>
>test code debug sort keywords
>
>ZUCS Print
>
>2011
>
>3333333
>
>Another Testing Book
>
>Yue Chen
>
>test code sort keywords
>
>ZUCS Print2
>
>2012
>
>2222222
>
>The Testing Book
>
>CYLL
>
>keywords debug book
>
>ZUCS Print2
>
>2011
>
>6
>
>1: The Testing Book
>
>2: Yue Chen
>
>3: keywords
>
>4: ZUCS Print
>
>5: 2011
>
>3: blablabla

## Sample Output:
>1: The Testing Book
>
>1111111
>
>2222222
>
>2: Yue Chen
>
>1111111
>
>3333333
>
>3: keywords
>
>1111111
>
>2222222
>
>3333333
>
>4: ZUCS Print
>
>1111111
>
>5: 2011
>
>1111111
>
>2222222
>
>3: blablabla
>
>Not Found

# 心得与体会
1. c++11后不支持gets。而pat的编译器采用的是c++14。因此要采用fgets(buffer,buffer_size,stdin)来从标准输入中获取一行字符串。其中buffer是char数组，buffer_size则是buffer这个数组的长度，stdin则是一个全局FILE指针，当include\<cstdio>后就会有。与gets不同的是，fgets会把末尾的\n也会读到buffer中，因此在对字符串比较精确要求的算法(比如hash)中，需要把末尾的\n除去。
2. linux中的换行符(\n)和windows中的换行符(\r\n)不同，因此如果可以，尽量用系统提供的gets()或fgets()。手写的时候，注意系统的差别。
3. char的数值是可以小于0的，但这并不出现在常规的ASCII码表内，只会出现在类似于utf-8的编码上。
4. 不必过分信任题目给的条件，在不超内存的情况下，数组可以尽量给大一点。比如本题目给定的year的范围为[1000,3000]，但实际上如果我用该数值-1000作为hash值，同时用size=2001的hashtable，会出现段错误。(其实后来发现，可能是自己写错了，让hashValue成为负数了哈哈哈。
