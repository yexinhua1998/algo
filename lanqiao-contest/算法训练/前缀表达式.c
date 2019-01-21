#include<stdio.h>
int main(){
	int add(int x,int y),minus(int x,int y),mul(int x,int y),divide(int x,int y);
	//minus(x,y)Îªx-y£¬divide£¨x,y)Îªx/y
	char ch;
	int (*p)(int x,int y),result,x,y;
	ch=getchar();
	scanf("%d %d",&x,&y);
	switch(ch){
		case '+':p=add;break;
		case '-':p=minus;break;
		case '*':p=mul;break;
		case '/':p=divide;break;
	}
	printf("%d",(*p)(x,y));
	return 0;
}

int add(int x,int y){
	return (x+y);
}

int minus(int x,int y){
	return x-y;
}

int mul(int x,int y){
	return x*y;
}

int divide(int x,int y){
	return x/y;
}
