#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#define STR_LEN 200
#define HL1 99991 //第一种哈希表长度
#define HL2 4000 //第二种哈希表长度
using std::string;
using std::vector;
using std::scanf;
using std::printf;
using std::fgets;
using std::sort;
using std::getchar;
using std::strlen;
using std::sscanf;


class HashItem{
	public:
		string key;
		int value;
		HashItem(string _key,int _value){
			key=_key;
			value=_value;
		}
};

vector<HashItem> bht[HL1];//book的hashtable
vector<HashItem> aht[HL1];//author
vector<HashItem> kht[HL1];//key word
vector<HashItem> pht[HL1];//publisher
vector<HashItem> yht[HL2];//year

int n;
/*
bool cmp(int x,int y){
	printf("x=%d y=%d bookid[x]=%d bookid[y]=%d\n",x,y,bookid[x],bookid[y]);
	if(bookid[x]>bookid[y]) return true;
	else return false;
}*/

int hf1(string key){
	int size=key.size();
	int hv=0;
	int i;

	for(i=0;i<size;i++) hv+=(int)((unsigned char)key[i]);
	return hv%HL1;
}

int hf2(string key){
    //修改2:加入%HL2,hash表长度変大
    int temp;
	sscanf(key.c_str(),"%d",&temp);
    return temp%HL2;
}

string getline(){
	char temp[STR_LEN];
    string s;
    int len;
	fgets(temp,STR_LEN,stdin);
	//printf("get a line:%s\n",temp);
    s=temp;
    if(s.back()=='\n') return string(s.begin(),s.end()-1);
    else return s;
}


void insert(vector<HashItem> *ht,int (*hf)(string key),string key,int value){
	//printf("insert:key=%s|| value=%d\n",key.c_str(),value);
	ht[hf(key)].push_back(HashItem(key,value));
}

vector<string> getkeywords(){
	char temp[STR_LEN];
	vector<string> result;
	int i,j;

	fgets(temp,STR_LEN,stdin);

    //修改1
    //i<STR_LEN
    //temp[i]!=' '
	for(i=0,j=0;i<STR_LEN;i++){
		if(temp[i]==' '||temp[i]=='\n'||temp[i]=='\0'||temp[i]=='\r'){
			result.push_back(string(temp+j,temp+i));
			if(temp[i]!=' ') break;
			else j=i+1;
		}
	}
	return result;
}

void input(){
	int i,j;
	vector<string> keywords;
	int size;
	int bookid;

	scanf("%d",&n);
	for(i=0;i<n;i++){
		//printf("input loop:i=%d start\n",i);
		scanf("%d",&bookid);
		getchar();
		//printf("bookid=%d\n",bookid[i]);
		insert(bht,hf1,getline(),bookid);
		insert(aht,hf1,getline(),bookid);
		keywords=getkeywords();
		size=keywords.size();
		for(j=0;j<size;j++)
			insert(kht,hf1,keywords[j],bookid);
		insert(pht,hf1,getline(),bookid);
		insert(yht,hf2,getline(),bookid);
		//printf("input loop:i=%d done\n",i);
	}
}

void query(vector<HashItem> *ht,int (*hf)(string key),string key){
	vector<int> match;
	int hv;
	int size;
	int i;

	hv=hf(key);
	size=ht[hv].size();
	for(i=0;i<size;i++){
		//printf("key=%s value=%d\n",ht[hv][i].key.c_str(),ht[hv][i].value);
		if(ht[hv][i].key==key) match.push_back(ht[hv][i].value);
	}
	/*printf("the match is :\n");
	for(i=0;i<size;i++){
		printf("%07d\n",match[i]);
	}
	printf("match:done\n");*/
	//printf("start to sort match:\n");
	sort(match.begin(),match.end());
	size=match.size();
	//printf("end to sort match.\n");
	if(size==0){
		printf("Not Found\n");
	}else{
		for(i=0;i<size;i++){
			printf("%07d\n",match[i]);
		}
	}

}

void output(){
	int m;
	int i;
	string temp,key;

	scanf("%d",&m);
	getchar();
	for(i=0;i<m;i++){
		//printf("output loop:i=%d start\n",i);
		temp=getline();
		key=string(temp.begin()+3,temp.end());
		//printf("key=%s\n",key.c_str());
		printf("%s\n",temp.c_str());
		switch(temp[0]){
			case '1':query(bht,hf1,key);break;
			case '2':query(aht,hf1,key);break;
			case '3':query(kht,hf1,key);break;
			case '4':query(pht,hf1,key);break;
			case '5':query(yht,hf2,key);break;
		}
		//printf("output loop:i=%d done\n",i);
	}
}

int main(){
	input();
	output();
	return 0;
}
