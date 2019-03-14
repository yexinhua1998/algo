#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
using std::scanf;
using std::printf;
using std::sort;
using std::memset;
using std::clock;
#define N 10000
#define M 100000
//kruskal

class Edge{
	public:
		int u;
		int v;
		int w;
		Edge(){}
		Edge(int _u,int _v,int _w){
			u=_u;
			v=_v;
			w=_w;
		}
		bool operator<(Edge& other){
			return w<other.w;
		}
};

Edge road[M];
int father[N];//Union find set
int cost[N];//Ci
int n;
int m;

void init(){
	int i;
	int u,v,w;
	
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++) father[i]=i;
	for(i=0;i<n;i++){
		scanf("%d",cost+i);
	}
	for(i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		road[i]=Edge(u-1,v-1,2*w+cost[u-1]+cost[v-1]);
	}
	//printf("init done\n");
}

int set_of(int u){
	//查询时，将路径上所有的元素的路径都进行缩短，以增加性能。 
	int i;
	static int stack[N];//用于优化的栈 
	int stacksize;
	int j;
	
	stacksize=0;
	i=father[u];
	stack[stacksize++]=u;
	stack[stacksize++]=i;
	while(i!=father[i]){
		i=father[i];
		stack[stacksize++]=i;
	}
	for(j=0;j<stacksize;j++) father[stack[j]]=i;
	return i;
}

void merge(int u,int v){
	//将v融合到u所在的集合中
	int i;
	
	father[set_of(v)]=set_of(u);
}

int kruskal(){
	int count;
	int i;
	int len;
	
	len=0;
	count=0;
	i=0;
	sort(road,road+m);
	while(count<n-1){
		//printf("loop\n");
		for(;i<m;i++){
			//printf("u=%d v=%d setof(u)=%d setof(v)=%d\n",road[i].u,road[i].v,set_of(road[i].u),set_of(road[i].v));
			if(set_of(road[i].u)!=set_of(road[i].v)) break;
		}
		//printf("u=%d v=%d\n",road[i].u,road[i].v);
		if(i<m){
			//printf("enter here\n");
			merge(road[i].u,road[i].v);
			count++;
			len+=road[i].w;
			i++;
		}
	}
	//printf("count=%d\n",count);
	return len;
}

void show_father(){
	int i;
	
	printf("father:");
	for(i=0;i<n;i++) printf("%d ",father[i]);
	printf("\n");
}

int main(){
	int len;
	int i;
	int min;
	clock_t start;
	
	start=clock();
	init();
	len=kruskal();
	//show_father();
	//printf("len=%d\n",len);
	min=0x3f3f3f3f;
	for(i=0;i<n;i++){
		//因为最后要回去某个节点睡觉，所以要找一个Ci最小的节点用来睡觉 
		//printf("cost[%d]=%d\n",i,cost[i],i,degree[i]);
		if(cost[i]<min) min=cost[i];
	}
	printf("%d\n",len+min);
	//printf("use %.2f seconds\n",(clock()-start)/(float)CLOCKS_PER_SEC);
	return 0;
}
