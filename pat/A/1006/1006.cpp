#include<iostream>
#include<string>
using namespace std;

class People{
	public:
		string id;
		string signin;
		string signout;
};

int main(){
	int n,i;
	string signin_id,signout_id;
	string first("24:00:00"),last("00:00:00");
	
	cin>>n;
	People record[n];
	for(i=0;i<n;i++){
		cin>>record[i].id;
		cin>>record[i].signin;
		cin>>record[i].signout;
		
		//cout<<record[i].id<<endl;
		//cout<<record[i].signin<<endl;
		//cout<<record[i].signout<<endl;
	}
	for(i=0;i<n;i++){
		if(record[i].signin<=first){
			first=record[i].signin;
			signin_id=record[i].id;
		}
		if(record[i].signout>=last){
			last=record[i].signout;
			signout_id=record[i].id;
		}
	}
	cout<<signin_id<<' '<<signout_id<<endl;
	return 0;
}
