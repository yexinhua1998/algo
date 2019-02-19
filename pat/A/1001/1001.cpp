#include<iostream>
#include<stdio.h>
using namespace std;

void output3(int x){
	if(x<100) cout<<'0';
	if(x<10) cout<<'0';
	cout<<x;
}


int main(){
	long long int a,b,x,i=1;
	cin>>a>>b;
	x=a+b;
	
	while(x/(i*1000)!=0) i*=1000;
	
	cout<<x/i;
	i/=1000;
	if(x<0)x=-x;
		
	while(i!=0){
		cout<<',';
		output3((x/i)%1000);
		i/=1000;
	}
	return 0;
}
