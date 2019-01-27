#include<iostream>
#include<climits>
#define N 10000
using namespace std;
int n;
int data[N];

int main(){
	int i,j;
	int max=INT_MIN,sum;
	int start=-1,end=-1;
	cin>>n;
	//cout<<"n="<<n<<endl;
	for(i=0;i<n;i++){
		cin>>data[i];
		//cout<<data[i]<<' ';
	}
	//cout<<endl;
	for(i=0;i<n;i++){
		sum=0;
		for(j=i;j<n;j++){
			sum+=data[j];
			if(sum>max){
				max=sum;
				start=i;
				end=j;
			}
		}
	}
	if(max>0)cout<<max<<' '<<data[start]<<' '<<data[end]<<endl;
	else if(max==0&&start==1) cout<<0<<' '<<data[start]<<' '<<data[end]<<endl;
	else cout<<0<<' '<<data[0]<<' '<<data[n-1]<<endl;
	return 0;
}
