#include<cstdio>
#include<cstring>
using std::printf;
using std::scanf;
using std::memset;
#define N 100
#define M 1000
int n;
int m;
int matrix[N][M];

int main(){
	int i,j;
	int x,y;
	
	memset(matrix,0,sizeof(matrix));
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		matrix[x-1][i]=1;
		matrix[y-1][i]=-1;
	}
	for(i=0;i<n;i++){
		printf("%d",matrix[i][0]);
		for(j=1;j<m;j++){
			printf(" %d",matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
