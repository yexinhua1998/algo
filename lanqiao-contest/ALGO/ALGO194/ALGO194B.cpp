#include<cstdio>
#include<cmath>
using std::printf;
using std::scanf;
using std::pow;
using std::fgets;
#define N 50000

int n;
int m;
int ans[N];
int ans_num[0xfffff]={0};//ans_num[i]为答案为i的数量 
bool visited[0xfffff]={false};//visted[i]为答案i是否已经被计算 

int mask;

void init_mask(){
	int i;
	
	mask=pow(2,m)-1;
}

int get_ans(char temp[100]){
	int i;
	int result=0;
	
	for(i=0;temp[i]!='\n';i++){
		if(temp[i]==' ') continue;
		else{
			result=result<<1;
			if(temp[i]=='1') result++;
		}
	}
	return result;
}

void input(){
	int i;
	char temp[100];
	
	scanf("%d%d",&n,&m);
	getchar();
	init_mask();
	for(i=0;i<n;i++){
		fgets(temp,100,stdin);
		ans[i]=get_ans(temp);
	}
}


int main(){
	int count=0;
	int i,j;
	int ans_temp;
	
	input();
	for(i=0;i<n;i++){
		ans_num[ans[i]]++;
	}
	for(i=0;i<n;i++){
		if(!visited[ans[i]]){
			ans_temp=(~ans[i])&mask;
			count+=ans_num[ans[i]]*ans_num[ans_temp];
			visited[ans[i]]=true;
			visited[ans_temp]=true;
		}
	}
	printf("%d\n",count);
	return 0;
}
