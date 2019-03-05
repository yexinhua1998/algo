#include<stdio.h>
int main(){
	int **tri,line,i,j,x1,x2;
	scanf("%d",&line);
	tri=(int **)malloc(sizeof(int*)*line);
	for(i=0;i<line;i++){
		*(tri+i)=(int *)malloc(sizeof(int)*(i+1));
		for(j=0;j<=i;j++){
			scanf("%d",*(tri+i)+j);
		}
	}
	for(i=line-2;i>=0;i--){
		for(j=0;j<i+1;j++){
			x1=*(*(tri+i+1)+j);
			x2=*(*(tri+i+1)+j+1);
			*(*(tri+i)+j)+=x1>x2?x1:x2;
		}
	}
	printf("%d",**tri);
	return 0;
}
