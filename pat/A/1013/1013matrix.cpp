#include<iostream>
#include<cstring>
using std::cout;
using std::cin;
using std::endl;
//std::ios::sync_with_stdio(false);

#define N 1000
bool graph[N][N];
int n,m,k;
bool used[N];

void dfs(int city){
    int i;

    used[city]=true;
    for(i=0;i<n;i++){
        if(!used[i]&&graph[city][i]){
            //cout<<"city="<<city<<";i="<<i<<endl;
            dfs(i);
        }
    }
}

int main(){
    int i,j;
    int x,y;
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin>>n>>m>>k;
    int check[k],linked_num;
    for(i=0;i<n;i++) for(j=0;j<n;j++) graph[i][j]=false;
    for(i=0;i<m;i++){
        cin>>x>>y;
        graph[x-1][y-1]=true;
        graph[y-1][x-1]=true;
    }
    for(i=0;i<k;i++) cin>>check[i];
    for(i=0;i<k;i++){
        for(j=0;j<n;j++) used[j]=false;
        x=check[i]-1;
        used[x]=true;
        linked_num=0;
        for(j=0;j<n;j++){
            if(!used[j]){
                dfs(j);
                linked_num++;
            }
        }
        cout<<linked_num-1<<endl;
        //printf("%d\n",linked_num-1)
    }
    return 0;
}
