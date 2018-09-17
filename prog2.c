#include<stdio.h>
#include<stdlib.h>
void main(){
	int n,*a,*b,wait_t=0,turnaround_t=0;
	printf("Enter the no of processes:");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	b=(int*)malloc(n*2*sizeof(int));
	printf("Enter the burst time of each process:");
	for(int i=0; i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0; i<n-1;i++){
		int pos=i;
		for(int j=i+1; j<n;j++){
			if(a[j]<a[pos]){
				pos=j;
			}
		}
		if(pos!=i){
			int temp=a[i];
			a[i]=a[pos];
			a[pos]=temp;
		}
	}
	for(int i=0; i<n;i++){
		if(i==0){
			b[i*2+0]=0;
			b[i*2+1]=a[0];
			wait_t+=b[i*2+0];
			turnaround_t+=b[i*2+1];
			continue;
		}
		b[i*2+0]=b[(i-1)*2+1];
		b[i*2+1]=b[i*2+0]+a[i];
		wait_t+=b[i*2+0];
		turnaround_t+=b[i*2+1];
		
	}
	printf("The avg waiting time is %f",wait_t*1.0/n);	
	printf("The avg turnaround time is %f",turnaround_t*1.0/n);	
	
}
