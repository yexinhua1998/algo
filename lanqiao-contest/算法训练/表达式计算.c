#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//¼Ó¼õ³Ë³ý
struct expression{
	char *capity;
	int len;
	int location;
};

int pow(int n,int index){
	int i,result=1;
	for(i=0;i<index;i++){
		result*=n;
	}
	return result;
}

int number_value(struct expression *exp){
	char number[10],result=0;
	int i;
	for(i=0;exp->capity[exp->location+i]<='9'&&exp->capity[exp->location+i]>='0';i++){
		number[i]=exp->capity[exp->location+i];
	}
	number[i]='\0';
	for(i=0;i<strlen(number);i++){
		result+=(number[i]-'0')*pow(10,strlen(number)-i-1);
		exp->location++;
	}
	return result;
}

int fac_value(struct expression *exp){
	int result;
	if(exp->capity[exp->location]=='('){
		exp->location++;
		result=exp_value(exp);
		exp->location++;
	}else{
		result=number_value(exp);
	}
	return result;
}

int term_value(struct expression *exp){
	int result;
	result=fac_value(exp);
	while(exp->capity[exp->location]=='*'||exp->capity[exp->location]=='/'){
		if(exp->capity[exp->location]=='*'){
			exp->location++;
			result*=fac_value(exp);
		}else if(exp->capity[exp->location]=='/'){
			exp->location++;
			result/=fac_value(exp);
		}
	}
	return result;
}

int exp_value(struct expression *exp){
	int result;
	result=term_value(exp);
	while(exp->capity[exp->location]=='+'||exp->capity[exp->location]=='-'){
		if(exp->capity[exp->location]=='+'){
			exp->location++;
			result+=term_value(exp);
		}else{
			exp->location++;
			result-=term_value(exp);
		}
	}
	return result;
}

int main(){
	struct expression exp;
	char origin_string[100];
	gets(origin_string);
	exp.capity=malloc(sizeof(char)*(strlen(origin_string)+1));
	strcpy(exp.capity,origin_string);
	exp.len=strlen(origin_string);
	exp.location=0;
	printf("%d",exp_value(&exp));
	return 0;
} 
