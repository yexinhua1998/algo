#include<iostream>
#include<cstring>
using namespace std;
#define N 102
#define M 5
#define WORD_SIZE 10

int main(){
	char data[N];
	char outputs[M][WORD_SIZE];
	int top=0;
	int sum=0;
	int temp;
	int i;
	
	cin>>data;
	for(i=0;data[i]!='\0';i++) sum+=data[i]-'0';
	if(sum==0){
		cout<<"zero"<<endl;
		return 0;
	}
	while(sum!=0){
		temp=sum%10;
		switch(temp){
			case 0:strcpy(outputs[top++],"zero");break;
			case 1:strcpy(outputs[top++],"one");break;
			case 2:strcpy(outputs[top++],"two");break;
			case 3:strcpy(outputs[top++],"three");break;
			case 4:strcpy(outputs[top++],"four");break;
			case 5:strcpy(outputs[top++],"five");break;
			case 6:strcpy(outputs[top++],"six");break;
			case 7:strcpy(outputs[top++],"seven");break;
			case 8:strcpy(outputs[top++],"eight");break;
			case 9:strcpy(outputs[top++],"nine");break;
		}
		sum=sum/10;
	}
	for(i=top-1;i>=0;i--){
		cout<<outputs[i];
		if(i==0) cout<<'\n';
		else cout<<' ';
	}
	return 0;
}
