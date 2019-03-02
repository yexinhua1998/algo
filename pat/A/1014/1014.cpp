#include<cstdio>
#include<cstdlib>
#include<climits>
#define INF INT_MAX
#define N 25
#define M 15
#define K 1005
#define Q 1005
using std::printf;
using std::scanf;
using std::exit;

class Queue{
	public:
		int data[N];
		int front;
		int rear;
		Queue(){
			front=0;
			rear=0;
		}
		bool empty(){
			return front==rear;
		}
		bool full(){
			return this->size()==N;
		}
		int size(){
			return rear-front;
		}
		void push(int _data){
			if(this->full()) exit(1);
			data[rear%N]=_data;
			rear++;
		}
		int pop(){
			int temp;
			if(this->empty()) exit(1);
			temp=data[front%N];
			front++;
			return temp;
		}
		int head(){
			return data[front%N];
		}
};

class Time{
	public:
		int hour;
		int min;
		Time(){}
		Time(int h,int m){
			hour=h;
			min=m;
			if(min>=60){
				hour+=(min/60);
				min=min%60;
			}
		}
		void show(){
			printf("%.2d:%.2d\n",hour,min);
		}
		Time operator+(Time other){
			//printf("plus:");
			//printf(" %d %d\n",this->hour+other.hour,this->min+other.min);
			return Time(this->hour+other.hour,this->min+other.min);
		}
};

Queue server[M];
int process_time[K];
int query[Q];
int n,m,k,q;
Time quit_time[K];
Time start_time[K];

bool can_in(){
	//�ж��Ƿ��ܽ����Ŷ�
	int i;
	for(i=0;i<n;i++){
		if(server[i].size()<m) return true;
	} 
	return false;
}

int find_shortest(){
	//Ѱ����̵ĵ�һ������
	int i,j=-1;
	int min=INF;
	for(i=0;i<n;i++){
		if(min>server[i].size()){
			min=server[i].size();
			j=i;
		}
	} 
	return j;
}

int get_min_time(){
	//�����������뿪�����ҵ������ʱ��
	int min=INF,processing,i;
	for(i=0;i<n;i++){
		if(server[i].empty()) continue;
		processing=server[i].head();
		if(min>process_time[processing]) min=process_time[processing];
	}
	return min;
}

void let_time_goes(int time){
	//���������ڰ���ҵ����˵�ʱ�����
	int i,processing;
	for(i=0;i<n;i++){
		if(server[i].empty()) continue;
		processing=server[i].head();
		process_time[processing]-=time;
	}
}

int quit_one(){
	//�õ�һ��process_time=0�����˳�
	int i,processing;
	for(i=0;i<n;i++){
		if(server[i].empty()) continue;
		processing=server[i].head();
		if(process_time[processing]==0){
			server[i].pop();
			return processing;
		}
	} 
}

void init_start_time(){
	int i;
	for(i=0;i<k;i++) start_time[i].hour=-1;
}

void update_start_time(Time now){
	int i,processing;
	
	for(i=0;i<n;i++){
		if(server[i].empty()) continue;
		processing=server[i].head();
		if(start_time[processing].hour==-1) start_time[processing]=now;
	}
}

int main(){
	int min,minj;
	Time now(8,0),temp;
	int i,j;
	int x;//��¼�ֵ��Ĺ˿� 
	int processing;
	bool can_served;
	
	//input
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(i=0;i<k;i++) scanf("%d",process_time+i);
	for(i=0;i<q;i++) scanf("%d",query+i);
	
	//simulation
	x=0;
	init_start_time();
	for(i=0;i<2*k;i++){
		if(can_in()&&x<k){
			//����δ���һ���ʣ��˿ͣ�ѡ����̵Ĳ���
			minj=find_shortest();
			if(minj==-1) exit(2);
			server[minj].push(x++);
		}else{
			//�����������Ѿ�û��ʣ��˿ͣ������ʱ����̵Ŀ��˳���
			update_start_time(now);
			min=get_min_time();
			if(min==INF) exit(3);
			now=now+Time(0,min);//ģ���ȥ��min���� 
			let_time_goes(min);
			processing=quit_one();
			quit_time[processing]=now;
		}
	}
	
	//output
	for(i=0;i<q;i++){
		temp=start_time[query[i]-1];
		if(temp.hour>=17){
			printf("Sorry\n");
		}else{
			quit_time[query[i]-1].show();
		}
	}
	
	//��¼start_time��������start_time���ж��Ƿ�Ӧ�����Sorry 
	return 0;
}
