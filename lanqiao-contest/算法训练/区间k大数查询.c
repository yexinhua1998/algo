#include<stdio.h>
#include<stdlib.h>
int len;
int main(){
	int n,m,s,r,k,i,j,a[1000],*p,b[1000],swap(int b[]),result[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d %d %d",&s,&r,&k);
		len=r-s+1;
		for(j=0;j<len;j++){
			b[j]=a[s+j-1];
		}
		swap(b);
		result[i]=b[k-1];
	}
	for(i=0;i<m;i++){
		printf("%d\n",result[i]);
	}
	return 0;
}

int swap(int b[]){
	int i,j,k,t;
	for(i=0;i<len;i++){
		k=i;
		for(j=i;j<len;j++){
			if (b[j]>b[k]){
				k=j;
			}
		}
		if (k!=i){
			t=b[i];
			b[i]=b[k];
			b[k]=t;
		}
	}
	return 0;
}
