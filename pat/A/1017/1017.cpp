#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 10000
#define K 100
using std::scanf;
using std::printf;
using std::sort;
using std::memset;

class Customer{
public:
	int in_sec;
	int process_sec;
	int wait_sec;
	Customer(){wait_sec=0;}
	void input(){
		int hour,min,sec,process_min;
		scanf("%d:%d:%d %d",&hour,&min,&sec,&process_min);
		in_sec=(hour*60+min)*60+sec;
		process_sec=60*process_min;
	}
	bool operator>(Customer other)const{
		return in_sec>other.in_sec;
	}
	bool operator==(Customer other)const{
		return in_sec==other.in_sec;
	}
	bool operator<(Customer other)const{
		return in_sec<other.in_sec;
	}
};

Customer list[N];
Customer *windows[K];
int n;
int k;
int open_sec=8*60*60;
int close_sec=17*60*60;
int now;

int main(){
	int i;
	int next;
	double sum;
	int count;
	bool is_empty=false;//是否所有银行窗口都已无人

	memset(windows,0,sizeof(windows));

	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++) list[i].input();

	sort(list,list+n);

	now=list[0].in_sec;
	next=0;
	while(true){
		is_empty=true;
		if(now>=open_sec){
			for(i=0;i<k;i++){
				if(windows[i]!=NULL){
					windows[i]->process_sec--;
					if(windows[i]->process_sec==0) windows[i]=NULL;
				}
				if(next<n){
					if(windows[i]==NULL && list[next].in_sec<=now && list[next].in_sec<=close_sec){
						windows[i]=list+next;
						next++;
					}
				}
				is_empty=is_empty && windows[i]==NULL;
			}
		}
		for(i=next;i<n;i++){
			if(list[i].in_sec<=now && list[i].in_sec<=close_sec)
				list[i].wait_sec++;
			else 
				break;
		}
		now++;
		if(is_empty&&now>close_sec) break;
	}
	count=0;
	for(i=0;i<n;i++){
		if(list[i].in_sec<=close_sec){
			count++;
			sum+=list[i].wait_sec;
		}
	}
	if(count>0) printf("%.1lf\n",(sum/count)/60);
	else printf("0.0\n");
	return 0;
}