#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define N 30
using std::printf;
using std::scanf;
using std::string;
using std::vector;
using std::strlen;
using std::memset;

int dcount1[10];//原来数的每个数字的个数 
int dcount2[10];//变换后数字的每个数字的个数 

vector<int> num1;
vector<int> num2;

void getnum1(){
	char temp[N];
	int i,size;
	
	scanf("%s",temp);
	size=strlen(temp);
	for(i=size-1;i>=0;i--) num1.push_back(temp[i]-'0');
}

void count(vector<int>& num,int dcount[10]){
	int i,size;
	size=num.size();
	memset(dcount,0,sizeof(int)*10);
	for(i=0;i<size;i++) dcount[num[i]]++;
}

void getnum2(){
	int rest=0;
	int i;
	int size;
	int temp;
	
	size=num1.size();
	rest=0;
	for(i=0;i<size;i++){
		temp=2*num1[i]+rest;
		num2.push_back(temp%10);
		rest=temp/10;
	}
	while(rest!=0){
		num2.push_back(rest%10);
		rest=rest/10;
	}
}

bool dcount_equal(){
	int i;
	for(i=0;i<10;i++){
		if(dcount1[i]!=dcount2[i]) return false;
	}
	return true;
}

void output(vector<int>& num){
	int i,size;
	
	size=num.size();
	for(i=size-1;i>=0;i--) printf("%d",num[i]);
}

int main(){
	getnum1();
	count(num1,dcount1);
	//output(num1);
	//printf("\n");
	getnum2();
	count(num2,dcount2);
	printf("%s\n",dcount_equal()?"Yes":"No");
	output(num2);
	return 0;
}