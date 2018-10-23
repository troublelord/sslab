#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char name[20];
	struct node* br[5];
	int typ;// 0=Directory , 1=File
}node;

char Dtemp[50],Ftemp[10];
node *head=null;

node* createDir(char name[20]){
	node *temp = (node*) malloc(sizeof(node));
	temp->dir=null;
	strcpy(temp->name,name);
	temp->typ=0;
	return temp;
	
}
node* createFil(){
	node *temp = (node*) malloc(sizeof(node));
	temp->dir=null;
	strcpy(temp->name,Ftemp);
	temp->typ=1;
	return temp;
	
}

void findDir(){
	char temp[10];
	int len=strlen(Dtemp);
	int i=0;
	node *temp=head->nextDir;
	for(i=0;i<strlen;i++){
		for(;Dtemp[i]!='/' ;i++){
			temp[i-pos]=Dtemp[i];
		}
		temp[i]='/0';
		
		while(temp->br!=null && temp->typ=0){
			if(strcmp(temp->name,temp)!=0)
				*temp->nextDir=createNode();		
		}
	}
	
}

void insert(){
	
	
	if(head==null){
		node *temp = createNode();
	}
}

void main(){
    int ch,exitflag=0;
    //init();
    while(!exitflag){
        printf("1.Create new file\n2.Delete a directory\n3.Delete a file\n4.Search for a file\n5.Display the files\n6.Exit Program\n");
        printf("1.Create new file\n2.Delete a file\n3.Search for a file\n4.Display the files\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the path:");
                    scanf("%s",Dtemp);
                    printf("Enter the new file name:");
                    scanf("%s",Ftemp);
                    insert();
                    break;
            
            case 2:  printf("Enter the path:");
                    scanf("%s",Dtemp);
                   // deleteD();
                    break;
                    
            case 3: printf("Enter the path:");
                    scanf("%s",Dtemp);
            	    printf("Enter the file name:");
                    scanf("%s",Ftemp);
                  //  deleteF();
                    break;
            
            case 4: printf("Enter the path:");
                    scanf("%s",Dtemp);
                    printf("Enter the file name to be searched:");
                    scanf("%s",Ftemp);
                   // search();
                    break;
            
            case 5:// display();
                    break;
            
            
            case 6: printf("Exiting program!!!");
                    exitflag=1;
                    break;
            
        }
    }
        
}
