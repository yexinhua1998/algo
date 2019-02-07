#include<iostream>
#include<cstring>
#include<stdio.h>

using std::cout;
using std::cin;
using std::endl;
using std::memset;

class Node{
public:
    //链表节点类
    int city;
    Node* next;
    Node(int _city){
        city=_city;
        next=NULL;
    }
    ~Node(){
        if(next) delete next;
    }
};

class LinkList{
public:
    Node *head;
    LinkList(){
        head=new Node(-1);
    }
    void add(int city){
        Node *p;
        p=head->next;
        head->next=new Node(city);
        head->next->next=p;
    }
};

int n,m,k;
LinkList *map;
char *used;
int *lost_city;
int linked_num;//记录整个地图中连通图的数量
int *result;

void dfs(int city){
    Node *p;
    used[city]=1;
    p=map[city].head->next;
    while(p){
        //printf("p->city=%d\n",p->city);
        if(!used[p->city]) dfs(p->city);
        p=p->next;
    }
}

int main(){
    int i,j,x,y;
    int city;
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin>>n>>m>>k;
    used=new char[n];
    map=new LinkList[n];
    lost_city=new int[k];
    result=new int[n];
    for(i=0;i<m;i++){
        cin>>x>>y;
        map[x-1].add(y-1);
        map[y-1].add(x-1);
    }
    //输入被攻占的城市
    for(i=0;i<k;i++){
        cin>>lost_city[i];
    }
    for(i=0;i<n;i++){
        result[i]=-1;
    }

    for(i=0;i<k;i++){
        city=lost_city[i]-1;
        if(result[city]!=-1){
            cout<<result[city]<<endl;
            continue;
        }
        //cout<<"start a loop"<<endl;
        //cout<<"linked_num="<<linked_num<<endl;
        linked_num=0;
        //cout<<"used="<<(int*)used<<endl;
        //printf("init memory\n");
        memset(used,0,n);
        //printf("init memory done\n");
        //printf("lost_city=%d\n",lost_city[i]-1);
        //printf("used[0]=%d\n",used[0]);
        //printf("city=%d\n",city);
        used[city]=1;
        //printf("done\n");
        for(j=0;j<n;j++){
            //printf("j=%d\n",j);
            if(!used[j]){
                dfs(j);
                linked_num++;
            }
        }
        cout<<linked_num-1<<endl;
        result[city]=linked_num-1;
    }

    delete []used;
    delete []map;
    delete []lost_city;

    return 0;
}
