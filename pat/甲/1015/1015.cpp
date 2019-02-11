/************************
构造一个bool向量is_prime,is_prime[i]代表i是否为质数，以降低时间 

将读入的数字转换成对应进制的字符串
将字符串反转
再将字符串转换成数字
查询是否为质数 
*************************/

#include<cstdio>
#include<cmath>
#include<string>
#define N 100001
#define MAX_LEN 20
using std::printf;
using std::scanf;
using std::sqrt;
using std::string;

bool is_prime[N];

void init_is_prime(){
	int i,j;
	is_prime[0]=false;
	is_prime[1]=false;
	for(i=2;i<=N;i++){
		is_prime[i]=true;
		for(j=2;j*j<=i;j++){
			if(i%j==0){
				is_prime[i]=false;
				break;
			}
		}
	}
}

string get_str(int num,int radix){
	//将num转化成倒转的radix进制的数字字符串
	string num_str;
	int i;
	
	if(num==0){
		num_str="0";
		return num_str;
	}
	num_str.reserve(MAX_LEN);
	while(num!=0){
		num_str+=(char)((num%radix)+'0');
		num/=radix;
	}
	return num_str;
}

int str2int(string num_str,int radix){
	//将字符串转换成整型数字
	int i,x=1,sum=0;
	for(i=num_str.size()-1;i>=0;i--){
		sum+=(num_str[i]-'0')*x;
		x*=radix;
	}
	return sum;
}

int main(){
	int x,y;
	
	init_is_prime();
	do{
		scanf("%d",&x);
		if(x<0) break;
		scanf("%d",&y);
		if(!is_prime[x]){
			printf("No\n");
			continue;
		}
		x=str2int(get_str(x,y),y);
		if(!is_prime[x]) 
			printf("No\n");
		else 
			printf("Yes\n");
	}while(true);
	
	return 0;
}