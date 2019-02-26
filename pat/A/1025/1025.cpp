#include<cstdio>
#include<algorithm>
#include<vector>
#define N 100
#define K 300
using std::scanf;
using std::printf;
using std::sort;
using std::vector;

class Student{
	public:
		unsigned long long id;
		float score;
		int lid;//local_num(id)
		int lr;//local_rank;
		int fr;//final rank;
		Student(unsigned long long _id,float _score,int _lid){
			id=_id;
			score=_score;
			lid=_lid;
			lr=0;
			fr=0;
		}
		bool operator>(Student& other){
			if(score>other.score) return true;
			else if(score==other.score&&id<other.id) return true;
			return false;
		}
		bool operator==(Student& other){
			return (score==other.score&&id==other.id);
		}
		bool operator<(Student& other){
			return !((*this)>other)&&!((*this)==other);
		}
};

vector<Student> total;

void rank(vector<Student>& students,int type){
	float score=-1;
	int rank=-1;
	int i;
	int size;
	
	size=students.size();
	for(i=0;i<size;i++){
		if(students[i].score==score){
			if(type==0){
				students[i].lr=rank;
			}else{
				students[i].fr=rank;
			}
		}else{
			if(type==0){
				students[i].lr=i+1;
			}else{
				students[i].fr=i+1;
			}
			score=students[i].score;
			rank=i+1;
		}
	}
}

void merge(vector<Student>& students){
	int size;
	int i;
	
	size=students.size();
	for(i=0;i<size;i++) total.push_back(students[i]);
}

void get_local(int lid){
	int k;
	int i;
	unsigned long long sid;
	int size;
	float score;
	vector<Student> students;
	
	scanf("%d",&k);
	students.reserve(k);
	for(i=0;i<k;i++){
		scanf("%llu %f",&sid,&score);
		students.push_back(Student(sid,score,lid));
	}
	sort(students.rbegin(),students.rend());
	size=students.size();
	rank(students,0);
	//for(i=0;i<size;i++) printf("%llu %d %d\n",students[i].id,students[i].score,students[i].lr);
	merge(students);
}

void output(){
	int size;
	int i;
	
	size=total.size();
	printf("%d\n",size);
	for(i=0;i<size;i++) 
		printf("%013llu %d %d %d\n",total[i].id,total[i].fr,total[i].lid,total[i].lr);
}

int main(){
	int n;
	int i;
	int size;
	
	scanf("%d",&n);
	total.reserve(n*K);
	for(i=1;i<=n;i++) get_local(i);
	sort(total.rbegin(),total.rend());
	rank(total,1);
	output();
	return 0;
}