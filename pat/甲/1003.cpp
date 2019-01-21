#include<iostream>
#include<climits>
#include<cstring>
#include<cstdlib>

#define INF INT_MAX
#define MAX_N 500

using namespace std;


class Value{
	public:
		int length;
		int team_num;
		
		bool operator>(const Value& b){
			if(this->length>b.length) return true;
			else if(this->length==b.length&&this->team_num<b.team_num) return true;
			return false;
		}
		
		Value operator+(Value &b){
			Value temp;
			temp.length=this->length+b.length;
			temp.team_num=this->team_num+b.team_num;
			return temp;
		}
		
		void set(int len,int num){
			length=len;
			team_num=num;
		}
		
		Value(){
			length=INF;
			team_num=0;
		}
};

class U{
	//U���� 
	public:
		int citys[MAX_N];
		int size;
		Value citys_value[MAX_N];
		
		U(){
			memset(citys,0,sizeof(int)*MAX_N);
			size=0;
		}
		
		void add(int cityno,Value& v){
			//����һ���ڵ㵽U����
			citys[size]=cityno;
			citys_value[size++]=v;
		}
};

class S{
	//S����
	public:
		int citys[MAX_N];
		int size;
		
		S(int n){
			//��ʼ��citys 
			int i;
			for(i=0;i<n;i++) citys[i]=i;
			//��ʼ��size 
			size=n;
		}
		
		void remove(int no){
			//��citys�е�no����ȥ
			swap(citys[no],citys[size-1]);
			size--; 
		}
};


int team_num[MAX_N];
int n;
int m;
Value value_map[MAX_N][MAX_N];//�洢�ӵ�i���ڵ㵽��j���ڵ��value 
Value cost[MAX_N];//�洢src����i���ڵ��value 

int src;//Դ�� 
int desc;//�ص� 

int main(){
	int i,j,k,len;
	Value vmin;
	int x,y;
	int minx,miny;
	int minj;
	
	cin>>n>>m>>src>>desc;
	U u;
	S s(n);
	
	for(i=0;i<n;i++) cin>>team_num[i];
	for(i=0;i<m;i++){
		cin>>j>>k>>len;
		value_map[j][k].set(len,team_num[k]);
	}
	
	//prim�㷨
	cost[src].set(0,team_num[src]);
	u.add(src,cost[src]);
	s.remove(src);
	
	while(s.size!=0){
		vmin.set(INF,0);
		minx=-1;
		miny=-1;
		for(i=0;i<u.size;i++){
			for(j=0;j<s.size;j++){
				x=u.citys[i];
				y=s.citys[j];
				//cout<<'('<<x<<','<<y<<')';
				
				if(value_map[x][y].length==INF) continue;
				if(vmin>(cost[x]+value_map[x][y])){
					vmin=cost[x]+value_map[x][y];
					minx=x;
					miny=y;
					minj=j;
					//cout<<"get"<<endl;
				}//else cout<<"no get"<<endl;
			}
		}
		if(minx==-1&&miny==-1) exit(1);
		u.add(miny,vmin);
		cost[miny]=vmin;
		s.remove(minj);
	}
	
	cout<<cost[desc].length<<' '<<cost[desc].team_num<<endl;
	
	return 0;
}
