#include<iostream>
using namespace std;

int char2num(char ch){
    if(ch>='0'&&ch<='9') return ch-'0';
    else return ch-'a'+10;
}

int maxdigit(string strnum){
    int len=strnum.size();
    int max=0;
    int i,num;
    char digit;

    for(i=0;i<len;i++){
        digit=strnum[i];
        num=char2num(digit);
        if(num>max) max=num;
    }

    return max;
}

unsigned long long getnum(string strnum,unsigned long long radix){
    char digit;
    unsigned long long sum=0,x=1;
    int i,num;
    for(i=strnum.size()-1;i>=0;i--){
        digit=strnum[i];
        num=char2num(digit);
        sum+=x*num;
        x*=radix;
    }
    return sum;
}

int main(){
    string data[2];
    unsigned long long x,y,right,left,mid;
    int tag,radix,other;
    int i;
    unsigned long long result=0;


    cin>>data[0]>>data[1]>>tag>>radix;
    tag--;
    other=!tag;
    x=getnum(data[tag],radix);
    /*
    for(i=maxdigit(data[other])+1;;i++){
        if(i<2) i=2;
        y=getnum(data[other],i);
        if(y>x) break;
        else if(x==y){
            result=i;
            break;
        }
    }*/
    left=maxdigit(data[other])+1;
    right=x+1;
    if(left>right) swap(left,right);
    //cout<<"x="<<x<<"left="<<left<<"right="<<right<<endl;
    while(left<=right){
        mid=(left+right)/2;
        y=getnum(data[other],mid);
        //cout<<"right="<<right<<";left="<<left<<";mid="<<mid<<"y="<<y<<endl;
        if(x>y){
            left=mid+1;
        }else if(x<y){
            right=mid-1;
        }else{
            result=mid;
            break;
        }
    }

    if(result) cout<<result;
    else cout<<"Impossible";
    return 0;
}
