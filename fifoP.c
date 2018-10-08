#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int f=0,pos=0;
char ref[25];
char mem[10];

int isFind(int i){
	for(int j=0;j<f;j++){
		if(mem[j]==ref[i])
			return 1;
	}
	return 0;
}

int display(){
	int i=0;
	while(i<f){
		printf("%c ",mem[i]);
		i++;
	}		
	printf("\n");
}

int fifop(){
	int pgFault=0;
	int i=0;
	while(i<f){
		mem[i]=ref[i];
		display();
		pgFault++;
		i++;
	}	
	for(;i<strlen(ref);i++){
		
		if(isFind(i)){
			display();
			continue;
		}
		else{
			pgFault++;
			mem[pos]=ref[i];
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
