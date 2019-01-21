//Beaver's Calculator.c
//author:Sinward Ye

#include<stdio.h>
#include<stdlib.h>
#define N 200000

typedef struct problem_{
	int i;//科学家编号 
	long long a;
	int t;
}Problem;

typedef struct input_{
	int k;
	long long a;
	long long x;
	long long y;
	long long m;
}Input;

Input inputs[5000];

Problem *problems=NULL,*temp=NULL;

char compare(Problem *a,Problem *b){//a>b?
	if(a->t==b->t){
		return ((a->a)>(b->a)||((a->a)==(b->a)&&(a->i)>=(b->i)));
	}else{
		return (a->t)>(b->t);
	}
}

void assign(Problem *a,Problem *b){
	//b=a
	b->i=a->i;
	b->a=a->a;
	b->t=a->t;
}

void copy(Problem *a,Problem *b,int start,int end){
	//a->b
	int i=0;
	for(i=start;i<=end;i++){
		assign(a+i,b+i);
	}
}

void merge(int start,int end,int mid){
	//将data中start-mid 以及 (mid+1)-end 中的数据融合到temp中去 
	char result=0;
	int i=start,j=mid+1,k=start;
	while(i<=mid&&j<=end){
		result=compare(problems+i,problems+j);
		if(result){//*(left+i)>*(right+j)
			assign(problems+j,temp+k);
			j++;k++;
		}else{
			assign(problems+i,temp+k);
			i++;k++;
		}
	}
	if(i<=mid){
		for(;i<=mid;i++){
			assign(problems+i,temp+k);
			k++;
		}
	}
	if(j<=end){
		for(;j<=end;j++){
			assign(problems+j,temp+k);
			k++;
		}
	}
}

void merge_sort(int start,int end){
	
	int mid=0;
	if(start<end){
		mid=(end+start)/2;
		merge_sort(start,mid);
		//printf("left merge sort ok\n");
		merge_sort(mid+1,end);
		//printf("right merge sort ok\n");
		merge(start,end,mid);
		//printf("merge ok\n");
		copy(temp,problems,start,end);
		//printf("copy ok\n");
	}
}

int main(){
	int n=0,i=0,j=0,k=0,p=0,t=0,maxt=0,size=0;
	long long a=0,b=0,x=0,y=0,m=0;
	//p为指向当前输入的problem的指针,b为这次计算得到的问题所需资源量,t为问题所属的板块编号 

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %lld %lld %lld %lld",&(inputs[i].k),&(inputs[i].a),&(inputs[i].x)
		,&(inputs[i].y),&inputs[i].m);
		size+=inputs[i].k;
	}
	problems=(Problem*)malloc(sizeof(Problem)*(size+10));
	if(size<=N)temp=(Problem*)malloc(sizeof(Problem)*(size+10));
	for(i=0;i<n;i++){
		t=0;
		k=inputs[i].k;a=inputs[i].a;x=inputs[i].x;y=inputs[i].y;m=inputs[i].m;
		problems[p].a=a;problems[p].i=i;problems[p].t=t;
		p++;
		for(j=0;j<k-1;j++){
			b=(a*x+y)%m;
			if(b<a) t++;
			a=b;
			problems[p].a=a;problems[p].i=i;problems[p].t=t;
			p++;
		}
		if(t>maxt) maxt=t;
	}
	printf("%d\n",maxt);
	if(p+1<=N){
		merge_sort(0,p-1);
		for(i=0;i<p;i++){
			printf("%lld %d\n",problems[i].a,problems[i].i+1);
		}
	}
	return 0;
}

