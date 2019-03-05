#include<stdio.h>
int main(){
	int x;
	char *string;
	void rec(int x,int index);
	scanf("%d",&x);
	rec(x,0);
	return 0;
}

void rec(int x,int index){
	int quotinent=x/2,remainder=x%2;
	if(quotinent!=0){
		rec(quotinent,index+1);
	}
	if(remainder==1){
		if(quotinent!=0 )printf("+");
		if(index==0){
			printf("2(0)");
		}else if(index==1){
			printf("2");
		}else{
		printf("2(");
		rec(index,0);
		printf(")");
		}
	}
}
