#include<cstdio>
#include<algorithm>
#include<string>
using std::printf;
using std::scanf;
using std::sort;
using std::string;

#define N 1000
#define STR_LEN 30

class Record{
public:
    string username;
    string time;
    bool is_on_line;
    int min;
    int day;
    int hour;
    Record(){};
    Record(string _username,string _time,string _is_on_line){
        username=_username;
        time=_time;
        is_on_line=_is_on_line=="on-line";
    }
    bool operator>(Record other)const{
        //this>other
        if(this->username==other.username){
            return this->time>other.time;
        }else return this->username>other.username;
    }
    bool operator==(Record other)const{
        return (this->username==other.username)&&(this->time==other.time);
    }
    bool operator<(Record other)const{
        return !(*this>other)&&!(*this==other);
    }
    int get_num(string num){
        //从string num中读出数字
        return (num[0]-'0')*10+num[1]-'0';
    }
    void cal_time(){
        //"mm:dd:hh:mm"
        // 0123456789a
        min=get_num(string(time,9));
        hour=get_num(string(time,6,8));
        day=get_num(string(time,3,5));
    }
    int get_min(){
        //计算离月初的分钟数
        return min+60*hour+24*60*day;
    }
    int operator-(Record other){
        return this->get_min()-other.get_min();
    }
};

Record list[N];
int fee[24];
int n;

double cal_fee(Record start,Record end){
    int cents=0;
    int i,day_fee=0;
    while(start.day!=end.day||start.hour!=end.hour||start.min!=end.min){
        cents+=fee[start.hour];
        start.min++;
        start.hour+=start.min/60;
        start.min%=60;
        start.day+=start.hour/24;
        start.hour%=24;
    }
    return (double)cents/100;
}

int main(){
    char username[STR_LEN],time[STR_LEN],type[STR_LEN];
    int i;
    string username_now;
    double total_amont=0,user_fee;
    int flag;

    for(i=0;i<24;i++) scanf("%d",fee+i);

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s %s %s",username,time,type);
        list[i]=Record(username,time,type);
    }
    sort(list,list+n);

    for(i=0;i<n;i++) list[i].cal_time();

    username_now="";
    for(i=1;i<n;i++){
        if(username_now!=list[i].username){
            if(username_now!=""&&flag==1){
                printf("Total amount: $%.2lf\n",total_amont);
            }
            username_now=list[i].username;
            total_amont=0;
            flag=0;
        }

        if(!list[i].is_on_line&&list[i-1].is_on_line
            &&list[i].username==list[i-1].username){
            if(flag==0){
                printf("%s %s\n",username_now.c_str(),
                    string(list[i].time,0,2).c_str());
                flag=1;
            }
            user_fee=cal_fee(list[i-1],list[i]);
            total_amont+=user_fee;
            printf("%s %s %d $%.2lf\n",string(list[i-1].time,3).c_str(),
            string(list[i].time,3).c_str(),list[i]-list[i-1],
            user_fee);
        }
    }
    if(username_now!=""&&flag==1){
        printf("Total amount: $%.2lf\n",total_amont);
    }
    return 0;
}
