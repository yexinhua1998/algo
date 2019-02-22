#include<cstdio>
#include<queue>
#define N 32
using std::queue;
using std::printf;
using std::scanf;

int s1[N];//后序遍历的序列
int s2[N];//中序遍历的序列
int s1i[N];//s1的hash索引 s1i[x]=index(x) s1[index(x)]=x
int s2i[N];//s2的hash索引

class Node{
//二叉树节点类
public:
	Node *left;
	Node *right;
	int num;
	Node(int _num){
		num=_num;
		left=NULL;
		right=NULL;
	}
};

Node *tree;
int n;

void make(Node* &root,int x,int y){
	//根据从x到y的中序遍历序列，构造根为root的二叉树
	if(x>y) return;

	int root_num;
	int root_post_loc=-1;//根节点在后序序列的位置
	int root_in_loc=-1;//根节点在中序序列的位置
	int num;
	int i;

	for(i=x;i<=y;i++){
		num=s2[i];
		if(s1i[num]>root_post_loc){
			 root_post_loc=s1i[num];
			 root_num=num;
		}
	}
	root=new Node(root_num);
	root_in_loc=s2i[root_num];
	if(x<y){
		make(root->left,x,root_in_loc-1);
		make(root->right,root_in_loc+1,y);
	}
}

int main(){
	int i;
	queue<Node> q; 
	Node temp(0);
	bool flag=false;

	scanf("%d",&n);
	for(i=0;i<n;i++) 
		scanf("%d",s1+i);
	for(i=0;i<n;i++)
		scanf("%d",s2+i);
	for(i=0;i<n;i++){
		s1i[s1[i]]=i;
		s2i[s2[i]]=i;
	}
	make(tree,0,n-1);
	q.push(*tree);
	while(!q.empty()){
		temp=q.front();
		if(temp.left)
			q.push(*(temp.left));
		if(temp.right)
			q.push(*(temp.right));
		q.pop();
		if(flag)
			printf(" %d",temp.num);
		else
			printf("%d",temp.num);
		flag=true;
	}
	return 0;
}