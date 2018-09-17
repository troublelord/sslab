#include<stdio.h>
#include<stdlib.h>
void main(){
	int t,n,*a,wait_t=0,turnaround_t=0,count=0;
	printf("Enter the no of processes:");
	scanf("%d",&n);
	printf("Enter the time slice:");
	scanf("%d",&t);
	a=(int*)malloc(n*sizeof(int));
	printf("Enter the burst time of each process:");
	for(int i=0; i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0; count<n;i=(i+1)%n){
		if(a[i]>t){
			a[i]-=t;
			wait_t+=(n-count-1)*t;
			turnaround_t+=t;
		}	
		else if(a[i]>0){
			wait_t+=(n-count-1)*a[i];
			turnaround_t+=a[i];
			a[i]=0;
			count++;
			
		}
		
	}
	turnaround_t+=wait_t;
	printf("The avg waiting time is %f",wait_t*1.0/n);	
	printf("\nThe avg turnaround time is %f",turnaround_t*1.0/n);	
	
}
