#include<cstdio>
#define N 501
#define INF 0x7fffffff
using std::printf;
using std::scanf;

int road[N][N];//矩阵图
int capacity[N];//每个station的容量
int shortest_srclen[N];//源点到该点的最短长度

bool is_shortest[N][N];//表示该边为最短路径中的一部分
bool used[N];//最短路径已知的点
int n;
int m;
int cmax;
int desc;

int path[N];//深度搜索时候的路径
int path_len;//路径长度

int best_path[N];//最佳路径
int best_path_len;//最佳路径长度

int best_len=INF;

int minremainbike;
int minneedbike;

void input(){
	int i,j;
	int x,y,t;
	int min=INF,target;

	scanf("%d%d%d%d",&cmax,&n,&desc,&m);
	for(i=0;i<=n;i++){
		used[i]=false;
		shortest_srclen[i]=INF;
		for(j=0;j<=n;j++) road[i][j]=INF;
	}
	for(i=1;i<=n;i++) 
		scanf("%d",capacity+i);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&t);
		road[x][y]=t;
		road[y][x]=t;
	}
	for(i=0;i<=n;i++) 
		shortest_srclen[i]=road[0][i];
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			is_shortest[i][j]=false;
		}
	}
	used[0]=true;
	shortest_srclen[0]=0;
}

void dij(){
	int i,j,k;
	int min,target,minj;

	for(i=0;i<n;i++){
		min=INF;

		for(j=0;j<=n;j++){
			if(!used[j]&&shortest_srclen[j]<min){
				min=shortest_srclen[j];
				minj=j;
			}
		}

		if(min==INF) break;
		used[minj]=true;
		//更新shortest_srclen表
		for(j=1;j<=n;j++){
			if(!used[j]&&road[minj][j]!=INF&&min+road[minj][j]<shortest_srclen[j]){
				shortest_srclen[j]=min+road[minj][j];
			}
		}

		//记录最短路径
		for(j=0;j<=n;j++){
			if(used[j]&&road[j][minj]!=INF&&shortest_srclen[j]+road[j][minj]==min){
				is_shortest[j][minj]=true;
				is_shortest[minj][j]=true;
			}
		}
	}
}

void record(){
	int i;
	best_path_len=path_len;
	for(i=0;i<path_len;i++){
		best_path[i]=path[i];
	}
}

void dfs(int node,int len,int needbike,int remainbike){
	int i;
	int x,y,c;

	path[path_len++]=node;
	if(node==desc){
		if(len<best_len){
			best_len=len;
			minneedbike=needbike;
			minremainbike=remainbike;
			record();
		}else if(len==best_len){
			if(needbike<minneedbike){
				minneedbike=needbike;
				minremainbike=remainbike;
				record();
			}else if(remainbike<minremainbike){
				minremainbike=remainbike;
				record();
			}
		}
	}else{
		for(i=1;i<=n;i++){
			if(!used[i]&&is_shortest[node][i]){
				c=capacity[i];
				x=needbike;
				y=remainbike;
				if(c>=cmax/2){
					y+=c-cmax/2;
				}else{
					if(y>=(cmax/2-c)){
						y-=(cmax/2-c);
					}else{
						x+=(cmax/2-c-y);
						y=0;
					}
				}

				used[i]=true;
				dfs(i,len+road[node][i],x,y);
				used[i]=false;
			}
		}
	}
	path_len--;
}

void output(){
	int i;
	for(i=0;i<=n;i++) 
		used[i]=false;
	used[0]=true;
	path_len=0;
	minneedbike=INF;
	minremainbike=INF;
	dfs(0,0,0,0);
	printf("%d ",minneedbike);
	printf("%d",best_path[0]);
	for(i=1;i<best_path_len;i++) 
		printf("->%d",best_path[i]);
	printf(" %d",minremainbike);
}

int main(){
	input();
	dij();
	output();
}
