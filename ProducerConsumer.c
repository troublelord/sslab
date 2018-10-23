#include<stdio.h>

int mutex=0, n=0;

void producer(){
    if(mutex>=n){
        printf("Buffer full cannot produce item!!\n");
    }
    else{
        ++mutex;
        printf("Item Produced\n");
    }
    
}

void consumer(){
    if(mutex<=0){
        printf("Buffer is empty cannot consume item!!\n");
    }else{
        --mutex;
        printf("Item consumed\n");
    }
}

void main(){
    int ch=0;
    printf("Enter buffer limit:");
    scanf("%d",&n);
    while(ch!=3){
        printf("1.Produce\n2.Consume\n3.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: producer();
                    break;
            case 2: consumer();
                    break;
            case 3: 
                    printf("Exiting program!!!");
                    break;
            default: printf("Invalid choice");
            
        }
    }
}
