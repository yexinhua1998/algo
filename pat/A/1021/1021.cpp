#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 10001
using std::vector;
using std::printf;
using std::scanf;
using std::memset;
using std::sort;

int n;
bool visited[N];
bool global_visited[N];
int max_deepth[N];

vector<int> arcs[N];
int components=0;

int dfs(int node,int deepth){
	visited[node]=true;
	global_visited[node]=true;
	int max=deepth;
	int size=arcs[node].size();
	int i,j,temp;

	for(i=0;i<size;i++){
		j=arcs[node][i];
		if(!visited[j]){
			temp=dfs(j,deepth+1);
			if(temp>max) max=temp;
		}
	}
	visited[node]=false;
	return max;
}

int main(){
	int i;
	int a,b;
	int max=0;
	vector<int> deepest_root;
	int size;

	scanf("%d",&n);
	for(i=0;i<n-1;i++){
		scanf("%d%d",&a,&b);
		arcs[a].push_back(b);
		arcs[b].push_back(a);
	}
	memset(global_visited,0,n+1);
	for(i=1;i<=n;i++){
		memset(visited,0,n+1);
		if(!global_visited[i])
			components++;
		max_deepth[i]=dfs(i,1);
		//printf("max_deepth[%d]=%d\n",i,max_deepth[i]);
	}
	if(components==1){
		for(i=1;i<=n;i++){
			if(max_deepth[i]>max) max=max_deepth[i];
		}
		deepest_root.reserve(N);
		for(i=1;i<=n;i++){
			if(max_deepth[i]==max) deepest_root.push_back(i);
		}
		size=deepest_root.size();
		sort(deepest_root.begin(),deepest_root.end());
		for(i=0;i<size;i++)
			printf("%d\n",deepest_root[i]);
	}else{
		printf("Error: %d components\n",components);
	}

	return 0;
}