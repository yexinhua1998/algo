#include<cstdio>
#include<vector>
#include<cstring>
#define N 30
using std::printf;
using std::scanf;
using std::vector;
using std::strlen;

vector<int> num1;
vector<int> num2;

void getnum1(){
	char temp[N];
	int i,size;
	
	scanf("%s",temp);
	//printf("temp=%s\n",temp);
	size=strlen(temp);
	for(i=size-1;i>=0;i--) num1.push_back(temp[i]-'0');
}

void output(vector<int>& num){
	int i,size;
	
	size=num.size();
	for(i=size-1;i>=0;i--) printf("%d",num[i]);
	printf("\n");
}

vector<int> reverse(vector<int>& num){
	int i,size;
	vector<int> result;
	
	size=num.size();
	result.reserve(size);
	for(i=size-1;i>=0;i--){
		result.push_back(num[i]);
	}
	return result;
}

vector<int> plus(vector<int>& x,vector<int>& y){
	vector<int> result;
	int i,size,rest,temp;
	
	rest=0;
	result.reserve(x.size()+1);
	size=x.size();
	for(i=0;i<size;i++){
		temp=x[i]+y[i]+rest;
		result.push_back(temp%10);
		rest=temp/10;
	}
	while(rest!=0){
		result.push_back(rest%10);
		rest/=10;
	}
	return result;
}

bool is_ok(vector<int> &x){
	int i,j;
	
	for(i=0,j=x.size()-1;i<j;i++,j--)
		if(x[i]!=x[j])
			return false;
			
	return true;
}

int k;

int main(){
	int i;
	
	getnum1();
	scanf("%d",&k);
	for(i=0;i<=k;i++){
		if(is_ok(num1)) break;
		if(i==k) break;
		num2=reverse(num1);
		/*printf("num2=");
		output(num2);*/
		num1=plus(num1,num2);
		/*printf("num1=");
		output(num1);*/
	}
	
	output(num1);
	printf("%d",i);
	return 0;
}
