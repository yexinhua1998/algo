#include<stdio.h>
#include<string.h>
#define N 105
#define A 0
#define B 1

//cowboys.c
//By Sinward Ye
typedef double lint;
lint cowboys(char string[N+1],int len,char signal){
	int i=0,j=0;
	lint num[2][2][N];
	char start=0;
	char temp[N+1];
	//initialize
	if(len==1) return 1;
	memset(num,0,sizeof(num));
	start=string[0];
	num[start][start][0]=1;
	num[!start][!start][0]=0;
	num[start][!start][0]=0;
	num[!start][start][0]=0;
	if(string[0]==A&&string[1]==A){
		num[A][A][1]=1;
	}else if(string[0]==B&&string[1]==A){
		num[B][A][1]=1;
		num[A][B][1]=1;
		if(len==2&&signal) return 1;//ÌØÊâÇé¿ö 
		else if(len==2&&!signal) return 2;
	}else if(string[0]==B&&string[1]==B){
		num[B][B][1]=1;
	}else if(string[0]==A&&string[1]==B&&len==2&&signal) return 1;
	else if(string[0]==A&&string[1]==B&&len==2&&!signal) return 0;
	for(i=2;i<len;i++){
		//f(A,A,n)
		if(string[i]==A) num[A][A][i]=num[A][A][i-1]+num[A][B][i-1];
		else num[A][A][i]=0;
		
		//f(A,B,n)
		if(string[i]==B) num[A][B][i]=num[A][B][i-1];
		else if(string[i]==A&&string[i-1]==B) num[A][B][i]=num[A][B][i-2]+num[A][A][i-2];
		else num[A][B][i]=0;
		
		//f(B,A,n)
		if(string[i]==A) num[B][A][i]=num[B][A][i-1]+num[B][B][i-1];
		else if(string[i]==B&&string[0]==A&&i==len-1&&signal){
			for(j=0;j<len-2;j++){
				temp[j]=string[j+1];
			}
			num[B][A][i]=cowboys(temp,len-2,0);
		}
		else num[B][A][i]=0;
		
		//f(B,B,n)
		if(string[i]==B) num[B][B][i]=num[B][B][i-1];
		else if(string[i]==A&&string[i-1]==B) num[B][B][i]=num[B][A][i-2]+num[B][B][i-2];
		else num[B][B][i]=0;
	}
	/*//print
	for(i=0;i<len;i++)printf("%c",string[i]==A?'A':'B');
	printf("\n");
	
	printf("A A:");
	for(i=0;i<len;i++) printf("%.0f ",num[A][A][i]);
	printf("\n");
	
	printf("A B:");
	for(i=0;i<len;i++) printf("%.0f ",num[A][B][i]);
	printf("\n");
	
	printf("B A:");
	for(i=0;i<len;i++) printf("%.0f ",num[B][A][i]);
	printf("\n");
	
	printf("B B:");
	for(i=0;i<len;i++) printf("%.0f ",num[B][B][i]);
	printf("\n");*/
	return num[A][A][len-1]+num[A][B][len-1]+num[B][A][len-1]+num[B][B][len-1];
}

int main(){
	int n=0,i=0;
	char c=0;
	char string[N+1];
	char s[N+1];
	gets(s);
	n=strlen(s);
	for(i=0;i<n;i++) string[i]=s[i]=='A'?A:B;
	printf("%.0f\n",cowboys(string,n,1));
	return 0;
}
