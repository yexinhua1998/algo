#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

#define N 1000000

class Score{
public:
    string id;
    float value;
    bool operator>(Score& _s){
        return this->value>_s.value;
    }
};

class Student{
public:
    string id;

    int c;//c programing
    int m;//math
    int e;//english
    float a;//average

    int crank;
    int mrank;
    int erank;
    int arank;

    void set(string _id,int _c,int _m,int _e){
        id=_id;
        c=_c;
        m=_m;
        e=_e;
        a=(float)(c+m+e)/3;
    }
    Score getScore(char type){
        Score s;
        s.id=id;
        switch(type){
            case 'C':s.value=c;break;
            case 'M':s.value=m;break;
            case 'E':s.value=e;break;
            case 'A':s.value=a;break;
        }
        return s;
    }
    void printBestRank(){
        int bestrank=arank;
        char bestclass='A';
        if(bestrank>crank){
            bestrank=crank;
            bestclass='C';
        }
        if(bestrank>mrank){
            bestrank=mrank;
            bestclass='M';
        }
        if(bestrank>erank){
            bestrank=erank;
            bestclass='E';
        }
        cout<<bestrank<<' '<<bestclass<<endl;
    }
};

int _hash(string key){
    int i,sum=0,x=1;
    for(i=key.size()-1;i>=0;i--){
        sum+=(key[i]-'0')*x;
        x*=10;
    }
    return sum;
}

int n,m;
Student *hash_table[N];
Student *slist;//student list
string *qlist;//query list
Score *scolist;//score list

bool compare(Score s1,Score s2){
    return s1>s2;
}

int main(){
    int i;
    string id;
    int cpro,math,eng;
    int hash_value;
    Student *sp;
    float score_temp;
    int rank_temp;

    memset(hash_table,0,sizeof(hash_table));

    cin>>n>>m;
    //cout<<"n="<<n<<";m="<<m<<endl;
    slist=new Student[n];
    qlist=new string[m];
    scolist=new Score[n];

    for(i=0;i<n;i++){
        cin>>id>>cpro>>math>>eng;
        //cout<<"id="<<id<<" cpro="<<cpro<<" math="<<math<<" eng="<<eng<<endl;
        slist[i].set(id,cpro,math,eng);
        hash_value=_hash(id);
        hash_table[hash_value]=slist+i;
    }

    for(i=0;i<m;i++){
        cin>>qlist[i];
        //cout<<"get the query "<<i+1<<":"<<qlist[i]<<endl;
    }
    //cout<<"input done"<<endl;

    for(i=0;i<n;i++) scolist[i]=slist[i].getScore('C');
    sort(scolist,scolist+n,compare);
    score_temp=-1;
    rank_temp=-1;
    for(i=0;i<n;i++){
        id=scolist[i].id;
        hash_value=_hash(id);
        sp=hash_table[hash_value];
        if(scolist[i].value!=score_temp){
            sp->crank=i+1;
            score_temp=scolist[i].value;
            rank_temp=i+1;
        }else sp->crank=rank_temp;
    }

    for(i=0;i<n;i++) scolist[i]=slist[i].getScore('M');
    sort(scolist,scolist+n,compare);
    score_temp=-1;
    rank_temp=-1;
    for(i=0;i<n;i++){
        id=scolist[i].id;
        hash_value=_hash(id);
        sp=hash_table[hash_value];
        if(scolist[i].value!=score_temp){
            sp->mrank=i+1;
            score_temp=scolist[i].value;
            rank_temp=i+1;
        }else sp->mrank=rank_temp;
    }

    for(i=0;i<n;i++) scolist[i]=slist[i].getScore('E');
    sort(scolist,scolist+n,compare);
    score_temp=-1;
    rank_temp=-1;
    for(i=0;i<n;i++){
        id=scolist[i].id;
        hash_value=_hash(id);
        sp=hash_table[hash_value];
        if(scolist[i].value!=score_temp){
            sp->erank=i+1;
            score_temp=scolist[i].value;
            rank_temp=i+1;
        }else sp->erank=rank_temp;
    }

    for(i=0;i<n;i++) scolist[i]=slist[i].getScore('A');
    sort(scolist,scolist+n,compare);
    score_temp=-1;
    rank_temp=-1;
    for(i=0;i<n;i++){
        id=scolist[i].id;
        hash_value=_hash(id);
        sp=hash_table[hash_value];
        if(scolist[i].value!=score_temp){
            sp->arank=i+1;
            score_temp=scolist[i].value;
            rank_temp=i+1;
        }else sp->arank=rank_temp;
    }

    //应对查询
    for(i=0;i<m;i++){
        hash_value=_hash(qlist[i]);
        sp=hash_table[hash_value];
        if(sp) sp->printBestRank();
        else cout<<"N/A"<<endl;
    }

    return 0;
}
