#include<iostream>
#include<climits>
#include<cstring>
#define INF INT_MAX
#define N 500
using namespace std;

int n,m,src,desc;//������ ·���� Դ�� �յ� 
int path_num[N];//Դ�㵽ĳ�����·���� 
int shortest_dist[N];//Դ�㵽ĳ�������̾��� 
int dist[N][N];//����
int team_num[N];//���е��Ŷ�����
int max_team_num[N];//Դ�㵽ĳ������ 
bool visited[N];//�Ƿ���֪���·��

void dij(){
	int i,j;
	int min,minj;
	
	for(i=1;i<n;i++){
		//Ѱ����Դ��·����̵���δ��S�����еĽڵ� 
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
		if(min==INF&&minj==-1) break;//���޿ɵ���Ľڵ㣬�˳��㷨
		visited[minj]=true;
		//�������·����
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
					//����minj�ٵ�jΪ���·��
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

