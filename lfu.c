#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int f=0,pos=0;
char ref[25];
char mem[10];
char last[10];

int find(int i){
	for(int j=0;j<f;j++){
		if(mem[j]==ref[i])
			return j;
	}
	return -1;
}

int display(){
	int i=0;
	while(i<f){
		printf("%c ",mem[i]);
		i++;
	}		
	printf("\n");
}

int smallest(){
	int small=last[0],spos=0;
	for(int i=0;i<f;i++){
		if(last[i]<small){
			small=last[i];
			spos=i;
		}
		
	}
	return spos;
	
}

int fifop(){
	int pgFault=0;
	int i=0;
	while(i<f){
		mem[i]=ref[i];
		last[i]=1;
		display();
		pgFault++;
		i++;
	}	
	for(;i<strlen(ref);i++){
		pos=find(i);
		if(pos!=-1){
			++last[pos];
			display();
			continue;
		}
		else{
			pgFault++;
			int tpos=-1;
			int spos=smallest();
			mem[spos]=ref[i];
			last[spos]=1;
			pos=(pos+1)%f;
		}
		display();
	}
	return pgFault;	
}

void main(){
	int pgFault=0;
	printf("Enter the no of frames:");
	scanf("%d",&f);
	printf("Enter the reference string:");
	scanf("%s",ref);
	pgFault=fifop();
	printf("The no of page faults is %d",pgFault);

}
