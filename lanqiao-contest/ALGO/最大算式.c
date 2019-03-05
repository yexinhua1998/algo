#include<stdio.h>
#include<stdlib.h>
#define MAX 16
typedef long long int inter;
int main(){
	inter getsum(inter *a,inter start,inter end);
	inter test(inter *a,inter start,inter end,inter mulcount);
	inter N,K;
	inter i,a[MAX];
	scanf("%lld %lld",&N,&K);
	for(i=0;i<N;i++){
		scanf("%lld",&a[i]);
	}
	printf("%lld",test(a,0,N-1,K));
	return 0;
}

inter getsum(inter *a,inter start,inter end){
	inter sum=0,i;
	for(i=start;i<=end;i++){
		sum+=a[i];
	}
	return sum;
}

inter test(inter *a,inter start,inter end,inter mulcount){
	inter result[MAX];
	inter i,j,max=0;
	inter getsum(inter *a,inter start,inter end);
	if(mulcount==0){
		return getsum(a,start,end);
	}
	for(i=start,j=0;i<end;i++,j++){
		result[j]=(getsum(a,start,i)*test(a,i+1,end,mulcount-1));
		max=max>result[j]?max:result[j];
 	}
	return max;
}
