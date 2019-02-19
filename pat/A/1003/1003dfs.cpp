#include<iostream>
#include<climits>
#include<cstring>
#include<ctime>

#define INF INT_MAX
#define MAX_N 500

using namespace std;

int min_len=INF;
int min_len_count=0;
int max_team=0;

char used[MAX_N];

int n;
int m;
int desc;
int src;
int team_num[MAX_N];

class Node{
	public:
		int cityno;
		int len;
		Node *next;
		
		Node(int no,int length){
			cityno=no;
			len=length;
			next=NULL;
		}
		~Node(){
			//删除时，先删除后面的 
			if(next) delete next;
		}
};

class LinkList{
	public:
		Node *head;
		LinkList(){
			head=NULL;
		}
		~LinkList(){
			if(head) delete head;
		}
		void add(int no,int len){
			if(head){
				Node *p=head;
				head=new Node(no,len);
				head->next=p;
			}else{
				head=new Node(no,len);
			}
		}
};

LinkList road_list[MAX_N];

void search(int cityno,int acc_len,int acc_team){
	Node *p;
	int target,len;
	
	if(cityno==desc){
		if(acc_len<min_len){
			//当前路径比已知最短路径短
			min_len=acc_len;
			min_len_count=1;
			max_team=acc_team; 
		}else if(acc_len==min_len){
			//当前路径与已知最短路径长度相等
			min_len_count+=1;
			if(acc_team>max_team) max_team=acc_team;
		}
	}else{
		p=road_list[cityno].head;
		while(p){
			target=p->cityno;
			len=p->len;
			if(!used[target]){
				used[target]=1;
				search(target,acc_len+len,acc_team+team_num[target]);
				used[target]=0;
			}
			p=p->next;
		}
	}
}

int main(){
	/*clock_t start,end;
	start=clock();*/
	
	int i,j,k,len;
	
	memset(used,0,MAX_N);
	
	cin>>n>>m>>src>>desc;
	for(i=0;i<n;i++){
		cin>>team_num[i];
	}
	for(i=0;i<m;i++){
		cin>>j>>k>>len;
		road_list[j].add(k,len);
		road_list[k].add(j,len);
	}
	
	if(src==desc){
		cout<<1<<' '<<team_num[src]<<endl;
		return 0;
	}
	
	used[src]=1;
	search(src,0,team_num[src]);
	used[src]=0;
	
	cout<<min_len_count<<' '<<max_team<<endl;
	/*
	end=clock();
	cout<<"use time "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds."<<endl;*/
	return 0;
}
