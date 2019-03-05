#include<iostream>
using namespace std;
int n;

int main(){
	int floor_on=0,floor_to=0,cost=0;
	int i;
	
	cin>>n;
	for(i=0;i<n;i++){
		cin>>floor_to;
		if(floor_to>floor_on){
			cost+=6*(floor_to-floor_on);
		}else{
			cost+=4*(floor_on-floor_to);
		}
		cost+=5;
		floor_on=floor_to;
	}
	cout<<cost;
	return 0;
}
