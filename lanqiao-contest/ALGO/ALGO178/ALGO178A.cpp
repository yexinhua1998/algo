/*
˼·���ȵõ�һ������ͼ����С������
Ȼ����mask��ö����Ҫ���Σ������������ĵ�
����ÿ��������������εĽڵ㼰���Ӧ�Ĳ�������������ɾ��
Ȼ����ɾȥ���ֵĻ����ϣ����ñ����ε��ĵ�����С������
Ȼ���¼·�� 

������Ҫ�Ա����εĵ����ö�٣��ʲ���prim�㷨 
*/
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<ctime>
using std::scanf;
using std::printf;
using std::memset;
using std::vector;
using std::memcpy;
using std::pow;
using std::sort;
using std::clock;
#define NC 20
#define NJ 10
int nc;
int nj;
int m;//���� 
int dist[NC][NC];
int loc[NJ];//��ʼλ��
int desc;
bool have_people[NC];
char mask[NC];
int status_index;//ö�ٵ�״̬��Ϊ2��status_index�η�����ֵΪû���˵ĳ��е�ֵ�� 

class Method{
	public:
		//�洢һ������
		bool visited[NC];
		bool in_path[NC][NC];
		int pre[NC];
		int len;//������ 
		int use_node_num;
		Method(){
			memset(visited,0,sizeof(visited));
			memset(in_path,0,sizeof(in_path));
			memset(pre,0x3f,sizeof(pre));
			len=0;
			use_node_num=0;
		}
		Method(const Method &other){
			memcpy(visited,other.visited,sizeof(visited));
			memcpy(in_path,other.in_path,sizeof(in_path));
			memcpy(pre,other.pre,sizeof(pre));
			len=other.len;
			use_node_num=other.use_node_num;
		}
		bool operator<(Method& other){
			if(len<other.len) return true;
			else if(len==other.len&&use_node_num<other.use_node_num) return true;
			return false;
		}
};

vector<Method> result;

Method preprocess(Method& src){
	int i,j;
	Method result;
	vector<int> should_be_delete;
	int size;
	int x;
	
	should_be_delete.reserve(nc);
	result=src; 
	//printf("src.pre[1]=%d result.pre[1]=%d\n",src.pre[1],result.pre[1]);
	for(i=0;i<nc;i++){
		for(j=i;j!=0x3f3f3f3f;j=result.pre[j]){
			//printf("j=%d pre[j]=%d\n",j,result.pre[j]);
			if(mask[j]){
				//printf("enter the if\n");
				//���õ�ɾ�� 
				should_be_delete.push_back(i);
				break;
			}
		}
	}
	size=should_be_delete.size();
	/*printf("shoud be deleted:");
	for(i=0;i<size;i++){
		printf("%d ",should_be_delete[i]);
	}
	printf("\n");*/
	for(i=0;i<size;i++){
		x=should_be_delete[i];
		result.visited[x]=false;
		result.use_node_num--;
		result.len-=dist[x][result.pre[x]];
		result.in_path[x][result.pre[x]]=false;
		result.in_path[result.pre[x]][x]=false;
	}
	for(i=0;i<size;i++){
		x=should_be_delete[i];
		result.pre[x]=0x3f3f3f3f;
	}
	return result;
}

Method prim(Method& status){
	int min;
	int mini,minj;
	int i,j,k;
	int n=nc-status.use_node_num;
	
	//printf("enter prim\n");
	for(k=0;k<n;k++){
		//printf("k=%d\n",k);
		min=0x3f3f3f3f;
		mini=-1;
		minj=-1;
		for(i=0;i<nc;i++){
			if(status.visited[i]){
				for(j=0;j<nc;j++){
					if(!status.visited[j]&&!mask[j]&&dist[i][j]<min){
						mini=i;
						minj=j;
						min=dist[i][j];
					}
				}
			}
		}
		if(mini!=-1){
			//printf("mini=%d minj=%d\n",mini,minj);
			status.visited[minj]=true;
			status.in_path[mini][minj]=true;
			status.in_path[minj][mini]=true;
			status.pre[minj]=mini;
			status.len+=min;
			status.use_node_num++;
		}else{
			break;
		}
	}
	return status;
}

bool plus_mask(){
	//mask++
	int i;
	bool flag;
	int rest;
	
	flag=true;//�Ƿ����++ 
	for(i=0;i<nc;i++){
		if(!have_people[i]&&desc!=i&&mask[i]==0){
			flag=false;
			break;
		}
	}
	if(flag) return false;
	mask[0]++;
	rest=0;
	i=0;
	do{
		//ģ���λ 
		if(have_people[i]||i==desc){
			rest+=mask[i];
			mask[i]=0;
		}else{
			mask[i]+=rest;
			rest=mask[i]/2;
			mask[i]%=2;
		}
		i++;
	}while(i<nc&&rest!=0);
	return true;
}

void show_mask(){
	int i;
	
	printf("mask:");
	for(i=0;i<nc;i++) printf(" %d",mask[i]);
	printf("\n");
}

int get_node_num(){
	int i;
	int count;
	
	count=0;
	for(i=0;i<nc;i++) if(!mask[i]) count++;
	return count;
}

bool is_ok(Method status){
	int i;
	
	if(status.len==-1) return false;
	for(i=0;i<nj;i++){
		if(!status.visited[loc[i]]) return false;
	}
	return true;
}

void enum_span_tree(){
	int i;
	char mask[NC];
	Method temp;
	Method src;
	
	memset(mask,0,sizeof(mask));
	src.visited[desc]=true;
	src.use_node_num=1;
	src=prim(src);
	result.push_back(src);
	while(plus_mask()){
		//show_mask();
		temp=preprocess(src);.
		temp=prim(temp);
		if(is_ok(temp)){
			//printf("ok\n");
			result.push_back(temp);
		}
	}
}

int main(){
	int i,j;
	int u,v,d;
	int temp;
	int len;
	clock_t start;
	Method min;
	int size;
	
	start=clock();
	scanf("%d%d%d",&nc,&desc,&m);
	desc--;
	memset(dist,0x3f,sizeof(dist));
	memset(have_people,0,sizeof(have_people));
	for(i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&d);
		dist[u-1][v-1]=d;
		dist[v-1][u-1]=d;
	}
	scanf("%d",&nj);
	status_index=nc;
	for(i=0;i<nj;i++){
		scanf("%d",&temp);
		loc[i]=temp-1;
		if(!have_people[temp-1]){
			have_people[temp-1]=true;
			status_index--;
		}
	}
	enum_span_tree();
	min=result[0];
	size=result.size();
	for(i=1;i<size;i++){
		if(result[i]<min) min=result[i];
	}
	result[0]=min;
	printf("distance = %d\n",result[0].len);
	for(i=0;i<nj;i++){
		j=loc[i];
		printf("%d",j+1);
		while(j!=desc){
			j=result[0].pre[j];
			printf("-%d",j+1);
		}
		printf("\n");
	}
	//printf("use time:%.2f\n",(clock()-start)/(double)CLOCKS_PER_SEC);
	return 0;
} 
