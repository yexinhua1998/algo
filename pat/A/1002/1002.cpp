#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

class Poly{
	private:
		double *c;//系数 
		int k;//非零的项数 
		int size;
	public:
		Poly(int maxe){
			int i;
			
			k=0;
			size=maxe;
			c=new double[maxe+1];
			for(i=0;i<=maxe;i++) c[i]=0;
		}
		void add(int e,double coff){
			//e是指数，coff是系数
			if(c[e]==0) k++;
			c[e]+=coff;
			if(c[e]==0) k--; 
		}
		friend ostream& operator<<(ostream &output,Poly &poly){
			int i;
			output<<poly.k;
			for(i=poly.size;i>=0;i--){
				if(poly.c[i]!=0) printf(" %d %.1f",i,poly.c[i]);
			}
			//output<<endl;
			return output;
		}
};

int main(){
	int k1,k2,i;
	int maxe=0;
	
	cin>>k1;
	int e1[k1];
	double c1[k1];
	for(i=0;i<k1;i++){
		cin>>e1[i]>>c1[i];
		//cout<<e1[i]<<' '<<c1[i]<<' ';
		if(e1[i]>maxe) maxe=e1[i];
	}
	
	cin>>k2;
	int e2[k2];
	double c2[k2];
	for(i=0;i<k2;i++){
		cin>>e2[i]>>c2[i];
		//cout<<e2[i]<<' '<<c2[i]<<' ';
		if(e2[i]>maxe) maxe=e2[i];
	}
	
	//cout<<maxe;
	//cout<<endl;
	Poly poly(maxe);
	for(i=0;i<k1;i++) poly.add(e1[i],c1[i]);
	for(i=0;i<k2;i++) poly.add(e2[i],c2[i]);
	
	cout<<poly;
	
	return 0;
}
