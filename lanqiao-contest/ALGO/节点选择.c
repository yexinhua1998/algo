#include<stdio.h>
#include<stdlib.h>
#define N 100000
//节点选择.c

typedef struct _adjlist{//邻接表 
	int adjvex;
	struct _adjlist *next;
}adjlist;

void calculate(adjlist *nodes,int n,int a[],int b[],int f){
	adjlist *p=NULL;
	int flag=0;//标志是否有孩子 
	int i=0,an=0,bn=0;
	p=nodes[n].next;
	while(p){
		if(p->adjvex!=f) flag=1;
		p=p->next;
	}
	if(flag){//递推 
		p=nodes[n].next;
		while(p){
			if(p->adjvex!=f) calculate(nodes,p->adjvex,a,b,n);
			p=p->next;
		}
		p=nodes[n].next;
		//calculate an and bn
		an=nodes[n].adjvex;
		bn=0;
		while(p){
			if(p->adjvex!=f){//不是父亲 
				an+=b[p->adjvex];
				bn+=b[p->adjvex]>a[p->adjvex]?b[p->adjvex]:a[p->adjvex];
			}
			p=p->next;
		}
		a[n]=an;
		b[n]=bn;
	}else{//初始状态 
		a[n]=nodes[n].adjvex;
		b[n]=0; 
	}
	//printf("n=%d an=%d bn=%d\n",n,a[n],b[n]);
	return;
}

int main(){
	int n=0,a[N],b[N],i=0,c=0,d=0;
	adjlist nodes[N],*p=NULL;
	scanf("%d",&n);
	//initialize
	for(i=0;i<n;i++){
		scanf("%d",&(nodes[i].adjvex));
		nodes[i].next=NULL;
	}
	for(i=0;i<n-1;i++){
		scanf("%d %d",&c,&d);
		p=&(nodes[c-1]);while(p->next)p=p->next;
		p->next=(adjlist*)malloc(sizeof(adjlist));
		p=p->next;p->adjvex=d-1;p->next=NULL;
		p=&(nodes[d-1]);while(p->next)p=p->next;
		p->next=(adjlist*)malloc(sizeof(adjlist));
		p=p->next;p->adjvex=c-1;p->next=NULL;
	}
	calculate(nodes,0,a,b,-1);
	printf("%d\n",a[0]>b[0]?a[0]:b[0]);
	return 0;
}
