#include<cstdio>
#include<string>
#define N 3
using std::scanf;
using std::printf;
using std::string;

char num213(int num){
	if(num>=0&&num<=9) return num+'0';
	else{
		switch(num){
			case 10:return 'A';
			case 11:return 'B';
			case 12:return 'C';
		}
	}
}

string get13(int num){
	string s;
	int temp;
	
	s.reserve(3);
	temp=num/13;
	s.push_back(num213(temp));
	s.push_back(num213(num%13));
	return s;
}

int main(){
	int r,g,b;
	
	scanf("%d%d%d",&r,&g,&b);
	printf("#%s%s%s\n",get13(r).c_str(),get13(g).c_str(),get13(b).c_str());
	return 0;
}
