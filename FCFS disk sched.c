#include <stdio.h>#include<stdlib.h>int head,n,*req;void main() {    int DAT;    printf("Enter the current head position:");    scanf("%d",&head);    printf("Enter the no of requests:");    scanf("%d",&n);    req=(int*)malloc(sizeof(int)*n);    for(int i=0;i<n;i++){        printf("Enter request%d\n",i+1);        scanf("%d",&req[i]);         DAT+=abs(head-req[i]);        head=req[i];            }        printf("Total Disk Access Time:%d",DAT);}