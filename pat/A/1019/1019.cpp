#include<cstdio>
#include<vector>
#define LEN 64
using std::printf;
using std::scanf;
using std::vector;

int n,b;
vector<int> a;

void output(){
    int i,size;
    size=a.size();
    printf("%d",a[size-1]);
    for(i=size-2;i>=0;i--) printf(" %d",a[i]);
}

bool check(){
    int i,size;
    size=a.size();
    for(i=0;i<=size/2;i++){
        //printf("i=%d size-1-i=%d data1=%d data2=%d\n",i,size-1-i,a[i],a[size-1-i]);
        if(a[i]!=a[size-1-i]) return false;
    }
    return true;
}

int main(){
    a.reserve(LEN);
    scanf("%d%d",&n,&b);
    if(n==0){
        printf("Yes\n");
        printf("0");
    }else{
        while(n!=0){
            a.push_back(n%b);
            n/=b;
        }
        if(check()){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
        output();
    }
    return 0;
}
