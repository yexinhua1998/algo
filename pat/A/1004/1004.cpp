#include<iostream>
#include<cstring>
#define N 101
using namespace std;

class Node{
	public:
		int id;
		Node* next;
		Node(int _id){
			id=_id;
			next=NULL;
		}
		~Node(){
			if(next!=NULL) delete next;
		}
};

class LinkList{
	public:
		Node *head;
		LinkList(){
			head=NULL;
		}
		~LinkList(){
			if(!head) delete head;
		}
		void add(int no){
			if(head==NULL){
				head=new Node(no);
			}else{
				Node *p;
				p=head;
				head=new Node(no);
				head->next=p;
			}
		}
};

LinkList tree[N];
int max_deepth=1;//根层
int num[N];//num[i]表示第i+1层有多少个叶子节点 

void search(int id,int deepth){//从第1层开始搜索 
	Node *p;
	if(deepth>max_deepth) max_deepth=deepth;
	if(tree[id].head){//非叶子节点 
		p=tree[id].head;
		while(p){
			search(p->id,deepth+1);
			p=p->next;
		}
	}else{//叶子结点 
		num[deepth-1]++;
	}
} 

int getid(){
	char num[3];
	int result=0;
	cin>>num;
	result+=(num[0]-'0')*10;
	result+=(num[1]-'0');
	return result;
}

int main(){
	int n,m,i,j,k,id,id_temp;
	
	//initialize
	memset(num,0,sizeof(int)*N);
	
	//input
	cin>>n>>m;
	for(i=0;i<m;i++){
		id=getid();
		cin>>k;
		for(j=0;j<k;j++){
			id_temp=getid();
			tree[id].add(id_temp);
		}
	}
	
	search(1,1);
	
	cout<<num[0];
	for(i=1;i<max_deepth;i++){
		cout<<' '<<num[i];
	}
	cout<<endl;
	
	return 0;
}
