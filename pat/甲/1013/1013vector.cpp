#include<cstdio>
#include<cstring>
#define N 1000
using std::printf;
using std::scanf;
using std::memset;

class List{
public:
    int data[N];
    int length;
    List(){
        length=0;
    }
    void add(int _data){
        data[length++]=_data;
    }
};

int n,m,k;
List* graph;
bool* used;
int *check;
int linked_num;

void dfs(int x){
    int i,len;
    int y;
    used[x]=true;
    //printf("dfs(%d)\n",x);
    len=graph[x].length;
    for(i=0;i<len;i++){
        y=graph[x].data[i];
        if(!used[y]){
            //printf("y=%d\n",y);
            dfs(y);
        }
    }
}

int main(){
    int i,j;
    int x,y;
    scanf("%d%d%d",&n,&m,&k);
    graph=new List[n];
    used=new bool[n];
    check=new int[k];
    for(i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        graph[x-1].add(y-1);
        graph[y-1].add(x-1);
    }
    for(i=0;i<k;i++) scanf("%d",check+i);
    for(i=0;i<k;i++){
        linked_num=0;
        memset(used,0,n);
        x=check[i]-1;
        //printf("x=%d\n",x);
        used[x]=true;
        for(j=0;j<n;j++){
            if(!used[j]){
                //printf("j=%d\n",j);
                dfs(j);
                linked_num++;
            }
        }
        printf("%d\n",linked_num-1);
    }
    return 0;
}
