#include<stdio.h>
#include<stdlib.h>

int isFinished(int finish[], int n){
	int i;
	for(i=0;finish[i]==1 && i<n;i++);	
	if(i==n)
		return 1;
	else
		return 0;
}
int ispossible(int need[], int work[], int i, int m){
	int count=0;
	for(int j=0;j<m && (need +i*m)[j] <= work[j];j++){
		count++;
		
	}	
	if(count==m)
		return 1;
	else
		return 0;
}

void main(){
	int m, n, *available, *max, *need , *work, *allocation,*finish;
	printf("Enter the no of processes:");
	scanf("%d",&n);
	printf("Enter the no of resource types in system:");
	scanf("%d",&m);
	available=(int*)malloc(sizeof(int)*m);
	max=(int*)malloc(sizeof(int)*n*m);
	work=(int*)malloc(sizeof(int)*m);
	allocation=(int*)malloc(sizeof(int)*n*m);
	need=(int*)malloc(sizeof(int)*n*m);
	finish=(int*)malloc(sizeof(int)*n);
	printf("Enter the available resource in the system:");
	for(int i=0;i<m;i++){
		scanf("%d",&available[i]);
	}
	for(int i=0;i<n;i++){
		printf("Enter the maximum resource required for each process %d:",i+1);
		for(int j=0;j<m;j++){
			scanf("%d",&(max + i*m)[j]);
		}
	}
	for(int i=0;i<n;i++){
		printf("Enter the resource allocated for each process %d:",i+1);
		for(int j=0;j<m;j++){
			scanf("%d",&(allocation + i*m)[j]);
			(need + i*m)[j]=(max + i*m)[j]-(allocation + i*m)[j];
		}
	}
	for(int i=0;i<m;i++){
		work[i]=available[i];
		finish[i]=0;
	}
	
	int modify=1;
	while(1 && modify){
		modify=0;
		for(int i=0;i<n;i++){
			if(finish[i] ==0 && ispossible(need,work,i,m)){
				modify=1;
				finish[i]=1;
				for(int j=0;j<m;j++){			
					work[j] = work[j] + (allocation+ i*m)[j];
				}
			}
		}
		if(isFinished(finish, n)){
			printf("system is in safe state:");
			break;
		}
	}
	if(modify==0){
	printf("system is in deadlock state:");
		}
	
	/*for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",(available + i*m)[j]);	
		}
		printf("\n"); */
		
	
}
