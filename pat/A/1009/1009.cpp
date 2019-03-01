#include<iostream>
#include<cstring>
#define N 1000
using namespace std;

class Node{
    public:
        int e;//指数
        float a;//系数
        Node* next;
        Node(int _e,float _a){
            e=_e;
            a=_a;
            next=NULL;
        }
        ~Node(){
            if(next) delete next;
        }
};

class LinkList{
    public:
        Node* head;
        Node* end;
        LinkList(){
            head=new Node(-1,-1);//头结点
            end=head;
        }
        ~LinkList(){
            delete head;
        }
        Node* add(int e,float a){//add 按顺序插入
            Node *p1,*p2,*data;
            p1=head;
            p2=head->next;
            while(p2){
                if(e<p2->e){
                    p1=p2;
                    p2=p2->next;
                }else break;
            }
            //插入data
            data=new Node(e,a);
            p1->next=data;
            data->next=p2;
            if(data->next==NULL) end=data;
            return data;
        }
        //append从队尾插入
        Node *append(int e,float a){
            Node *data;
            data=new Node(e,a);
            end->next=data;
            end=data;
            return data;
        }
};

LinkList poly1,poly2,poly3;
Node* used[N+N+1];//通过这个线性表来查找对应指数的节点

int main(){
    int i,j,e;
    float a;
    int k1,k2,k3=0;
    Node* p1;
    Node* p2;
    Node* p3;


    //input
    cin>>k1;
    for(i=0;i<k1;i++){
        cin>>e>>a;
        poly1.append(e,a);
    }
    cin>>k2;
    for(i=0;i<k2;i++){
        cin>>e>>a;
        poly2.append(e,a);
    }

    memset(used,0,sizeof(Node*)*(k1+k2+1));

    //calculate
    p1=poly1.head->next;
    while(p1){
        p2=poly2.head->next;
        while(p2){
            e=p1->e+p2->e;
            a=p1->a*p2->a;
            //cout<<"e1,a1,e2,a2,e3,a3"<<p1->e<<' '<<p1->a<<' '<<p2->e<<' '<<p2->a<<' '<<e<<' '<<a<<endl;
            if(used[e]!=NULL){
                p3=used[e];
                p3->a+=a;
                if(p3->a==0) k3--;
            }else{
                p3=poly3.add(e,a);
                used[e]=p3;
                k3++;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }

    //output
    cout.precision(1);
    cout.setf(ios::showpoint);
    cout.setf(ios::floatfield,ios::fixed);

    cout<<k3;
    p3=poly3.head->next;
    while(p3){
        if(p3->a!=0) cout<<' '<<p3->e<<' '<<p3->a;
        p3=p3->next;
    }
    cout<<endl;

    return 0;
}
