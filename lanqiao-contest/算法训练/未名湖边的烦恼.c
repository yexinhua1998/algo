#include<stdio.h>
#include<stdlib.h>
int main(){
	int m,n,*a,i,count=0,len,j;
	float times(int m,int n),time;
	int check(int *a,int len);
	void update(int *a,int len,int m);
	scanf("%d %d",&m,&n);
	len=m+n;
	a=malloc((m+n)*sizeof(int));
	for(i=0;i<m+n;i++){
		if(i<m){
			a[i]=1;
		}else{
			a[i]=-1;
		}
	}
	time=times(m,n);
	for(i=0;i<time;i++){
		if(check(a,len)==1){
			count++;
		}
		if(i!=time-1){
			update(a,len,m);
		}
	}
	printf("%d",count);
	return 0;
}

float times(int m,int n){ 	//�������C(m+n,n) 
	float fac(int x),result;
	result=(fac(m+n)/(fac(m)*fac(n)));
	return result;
}

float fac(int x){
	int i;
	float count=1;
	for(i=1;i<=x;i++){
		count*=i;
	}
	return count;
}

void update(int *a,int len,int m){
	int i;
	if(a[len-1]==1){
		//����ǰ��ģ�ͬʱǰ�����е����һ��1�����Ϊ1
		update(a,len-1,m-1);
		//��������һ��1 
		for(i=len-2;i>0;i--){
			if(a[i]==1){
				break;
			}
		}
		a[i+1]=1;
		if(i+1!=len-1){
			a[len-1]=-1;
		}
		
	}else{
		//ץȡ���һ��1��Ȼ�������ƶ� 
		for(i=len-1;i>0;i--){
			if(a[i]==1){
				break;
			}
		}
		a[i+1]=1;a[i]=-1;
	}
}

int check(int *a,int len){
	int count=0,i,flag=1;
	for(i=0;i<len;i++){
		count+=a[i];
		if(count<0){
			flag=-1;
			break;
		}
	}
	return (flag);
}
