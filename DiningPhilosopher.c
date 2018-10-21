#include<stdio.h>

int mutex=0, n=0, chopstick[]={0,0,0,0,0},phil[]={0,0,0,0,0};

int isviable(){
    
    if(chopstick[n-1]||chopstick[(n)%5])
        return 0;
    else
        return 1;
}

int iseating(){
    if(phil[n-1])
        return 1;
    else
        return 0;
}

void main(){
    int ch=0;
    while(ch!=3){
        printf("1.Eat\n2.Think\n3.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter which philosopher:");
                    scanf("%d",&n);
                    if(iseating()){
                        printf("philosopher %d is already eating !!",n);
                        break;
                    }
                    else if(isviable()){
                        chopstick[n-1]=1;
                        chopstick[(n)%5]=1;
                        printf("Philosopher %d is eating\n",n);
                        phil[n-1]=1;
                    }
                    else{
                        printf("Philosopher %d cannot eat and is thinking\n",n);
                    }
                    break;
            case 2: printf("Enter which philosopher:");
                    scanf("%d",&n);
                    if(!iseating()){
                        printf("philosopher %d is already thinking !!",n);
                        break;
                    }
                    else{
                        chopstick[n-1]=0;
                        chopstick[(n)%5]=0;
                        printf("Philosopher %d is thinking\n",n);
                        phil[n-1]=0;
                    }
                    break;
            case 3: printf("Exiting program!!!");
                    break;
            
            default: printf("Invalid choice");
            
        }
    }
}
