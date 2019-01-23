#include<iostream>
#include<climits>
#include<cstring>
#define INF INT_MAX
#define N 500
using namespace std;

int n,m,src,desc;//城市数 路径数 源点 终点 
int path_num[N];//源点到某个点的路径数 
int shortest_dist[N];//源点到某个点的最短距离 
int dist[N][N];//距离
int team_num[N];//城市的团队数量
int max_team_num[N];//源点到某个城市 
bool visited[N];//是否已知最短路径

void dij(){
	int i,j;
	int min,minj;
	
	for(i=1;i<n;i++){
		//寻找离源点路径最短的且未在S集合中的节点 
		minj=-1;
		min=INF;
		for(j=0;j<n;j++){
			if(!visited[j]){
				if(shortest_dist[j]<min){
					min=shortest_dist[j];
					minj=j;
				}
			}
		}
		//cout<<"shortest:"<<minj<<' '<<min<<endl;
		if(min==INF&&minj==-1) break;//已无可到达的节点，退出算法
		visited[minj]=true;
		//更新最短路径表
		for(j=0;j<n;j++){
			if(!visited[j]){
				
				if(dist[minj][j]==INF) continue;
				//cout<<"j:"<<j<<' ';
				if(dist[minj][j]+shortest_dist[minj]<shortest_dist[j]){
					//cout<<"brench 1"<<endl;
					//cout<<"brench 2"<<endl;
					//cout<<max_team_num[minj]<<endl;
					//cout<<team_num[j]<<endl;
					//cout<<max_team_num[j]<<endl;
					//cout<<path_num[j]<<endl;
					//经过minj再到j为最短路径
					shortest_dist[j]=dist[minj][j]+shortest_dist[minj];
					max_team_num[j]=max_team_num[minj]+team_num[j];
					path_num[j]=path_num[minj];
				}else if(dist[minj][j]+shortest_dist[minj]==shortest_dist[j]){
					//cout<<"brench 2"<<endl;
					//cout<<max_team_num[minj]<<endl;
					//cout<<team_num[j]<<endl;
					//cout<<max_team_num[j]<<endl;
					//cout<<path_num[j]<<endl;
					if(max_team_num[minj]+team_num[j]>max_team_num[j]){
						max_team_num[j]=max_team_num[minj]+team_num[j];
					}
					path_num[j]+=path_num[minj];
				}//else cout<<"no breanch"<<endl;
				
			}
		} 
	}
}

int main(){
	int i,j,k,len;
	
	memset(visited,0,N);
	memset(max_team_num,0,sizeof(int)*N);
	memset(path_num,0,sizeof(int)*N);
	
	cin>>n>>m>>src>>desc;
	for(i=0;i<n;i++){
		cin>>team_num[i];
		for(j=0;j<n;j++) {
			if(i!=j) dist[i][j]=INF;
			else dist[i][j]=0;
		}
	}
	for(i=0;i<m;i++){
		cin>>j>>k>>len;
		dist[j][k]=len;
		dist[k][j]=len;
	}
	for(i=0;i<n;i++){
		shortest_dist[i]=dist[src][i];
		if(dist[src][i]!=INF&&i!=src){
			path_num[i]=1;
			max_team_num[i]=team_num[src]+team_num[i];
		}
		
	}
	visited[src]=true;
	
	max_team_num[src]=team_num[src];
	path_num[src]=1;
	dij();
	
	cout<<path_num[desc]<<' '<<max_team_num[desc]<<endl;
	
	return 0;
} 

