#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
using std::printf;
using std::scanf;
using std::vector;
using std::memset;
using std::for_each;

class Player{
	public:
		int at;//arrive time
		int st;//serving time
		int wt;//waiting time
		int pt;//playing time
		bool is_vip;
		bool start2play;
		Player(){}
		Player(int _at,int _pt,bool _is_vip){
			at=_at;
			pt=_pt;
			is_vip=_is_vip;
			wt=0;
			st=0;
			start2play=false;
		}
		bool operator<(Player& other){
			return at<other.at;
		}
};

class Table{
	public:
		int served;//the number of served people
		bool playing;
		bool is_vip;
		Player serving;//serving player
		Table(){
			served=0;
			is_vip=false;
			playing=false;
		}
};


#define N 10000
#define K 100
#define M K
int n;
int k;
int m;

int next_player=0;

class Queue{
	public:
		vector<Player> data;
		vector<Player>::iterator _front;
		Queue(){
			data.reserve(N);
			_front=data.begin();
		}
		void push_back(Player _data){
			data.push_back(_data);
		}
		bool empty(){
			return _front==data.end();
		}
		void pop_front(){
			_front++;
		}
		Player front(){
			return *_front;
		}
		vector<Player>::iterator begin(){
			return _front;
		}
		vector<Player>::iterator end(){
			return data.end();
		}
};


Queue notarrive;//people not arrived
vector<Player> arrived;//people arrived
vector<Player> played;//people who have played
Table tables[K];

Player get_player(){
	int hour;
	int min;
	int sec;
	int playtime;
	int is_vip;
	
	scanf("%d:%d:%d",&hour,&min,&sec);
	scanf("%d%d",&playtime,&is_vip);
	return Player(sec+min*60+hour*3600,playtime*60,is_vip);
}

bool cmp_at(Player& x,Player& y){
	return x.at<y.at;
}

void input(){
	int i;
	int temp;
	
	scanf("%d",&n);
	arrived.reserve(n);
	for(i=0;i<n;i++)
		notarrive.push_back(get_player());
	sort(notarrive.begin(),notarrive.end(),cmp_at);
	scanf("%d %d",&k,&m);
	for(i=0;i<m;i++){
		scanf("%d",&temp);
		tables[temp-1].is_vip=true;
	}
}

int ot=8*3600;//open time
int ct=21*3600;//close time
int now=ot;

void let_vip_play(){
	int i;
	int j;
	int size;
	
	i=0;
	j=next_player;
	size=arrived.size();
	while(i<k&&j<size){
		if(tables[i].playing||!tables[i].is_vip){
			i++;
		}else if(!arrived[j].is_vip||arrived[j].start2play){
			j++;
		}else{
			tables[i].playing=true;
			tables[i].serving=arrived[j];
			tables[i].serving.st=now;
			tables[i].served++;
			played.push_back(tables[i].serving);
			i++;
			
			arrived[j].start2play=true;
			j++;
		}
	}
}


void let_normal_play(){
	int i;
	
	for(i=0;i<k;i++){
		while(next_player<arrived.size()){
			if(arrived[next_player].start2play) next_player++;
			else break;
		}
		if(next_player>=arrived.size()) 
			break;
		if(tables[i].playing) 
			continue;
		tables[i].playing=true;
		tables[i].served++;
		tables[i].serving=arrived[next_player];
		tables[i].serving.st=now;
		played.push_back(tables[i].serving);
		
		next_player++;
	}
}

void let_played_out(){
	int i;
	
	for(i=0;i<k;i++){
		if(tables[i].playing&&tables[i].serving.pt==0){
			tables[i].playing=false;
		}
	}
}

void play(){
	int i;
	
	for(i=0;i<k;i++){
		if(tables[i].playing) tables[i].serving.pt--;
	}
}

void let_arrive(){
	while(!notarrive.empty()){
		if(notarrive.front().at<=now){
			arrived.push_back(notarrive.front());
			notarrive.pop_front();
		}else break;
	}
}

void wait(){
	int i;
	int size;
	
	size=arrived.size();
	for(i=next_player;i<size;i++) arrived[i].wt++;
}

void run(){
	
	while(now<ct){
		let_played_out();
		let_arrive();
		let_vip_play();
		let_normal_play();
		play();
		wait();
		now++;
	}
}

bool cmp_st(Player &x,Player &y){
	return x.st<y.st;
}

void print_time(int time){
	printf("%02d:",time/3600);
	time%=3600;
	printf("%02d:",time/60);
	time%=60;
	printf("%02d ",time);
}

int round_up2min(int time){
	float x;
	
	x=(float)time/60;
	if(x==(int)x) return (int)x;
	else return (int)x+1;
}

void print_player(Player &player){
	
	print_time(player.at);
	print_time(player.st);
	printf("%.0f\n",round(player.wt/60.0));
}

void output(){
	int i;
	
	sort(played.begin(),played.end(),cmp_st);
	for_each(played.begin(),played.end(),print_player);
	printf("%d",tables[0].served);
	for(i=1;i<k;i++) printf(" %d",tables[i].served);
}

int main(){
	int i;
	
	input();
	run();
	output();
	
	return 0;
}