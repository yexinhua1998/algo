#include<iostream>
using std::cout;
using std::cin;
using std::ios;
using std::endl;

char result[3]={'W','T','L'};
double data[3][3];
double max[3];
int maxj[3];

int main(){
    int i,j;

    for(i=0;i<3;i++) max[i]=0;
    for(i=0;i<3;i++) for(j=0;j<3;j++) cin>>data[i][j];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(data[i][j]>max[i]){
                max[i]=data[i][j];
                maxj[i]=j;
            }
        }
    }

    cout.setf(ios::floatfield,ios::fixed);
    cout.precision(2);
    for(i=0;i<3;i++) cout<<result[maxj[i]]<<' ';
    cout<<(max[0]*max[1]*max[2]*0.65-1)*2<<endl;
}
