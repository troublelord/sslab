#include<stdio.h>
#include<string.h>
#define true 1
#define false 0

char temp[10],dirFile[10][10];
int count=-1;

void insert(char temp[10]){
    if(doesExist(temp)){
    	printf("The file already exists\n");
    	return;
    }
    
    if(count==9){
        printf("Memory full cannot create new file !!\n");        
    }
    else{
        strcpy(dirFile[++count],temp);
        printf("File %s successfully created\n",temp);
    }
    
}
void deleteF(char temp[10]){
    for(int i=0;i<=count;i++){
        if(strcmp(dirFile[i],temp)==0){
            strcpy(dirFile[i],dirFile[count]);
            strcpy(dirFile[count--],"");
            return;
        }
    }
    
}

void search(char temp[10]){
    for(int i=0;i<=count;i++){
        if(strcmp(dirFile[i],temp)==0){
            printf("File %s found in the directory\n",temp);  
            return;
        }
    }
    printf("File %s not found in the directory\n",temp);
}

void doesExist(char temp[10]){
    for(int i=0;i<=count;i++){
        if(strcmp(dirFile[i],temp)==0){
            return 1;
        }
    }
    return 0;
}

void display(){
    for(int i=0;i<=count;i++){
        printf("%s\n",dirFile[i]);   
    }
    
}

void main(){
    int ch,exitflag=false;
    while(!exitflag){
        printf("1.Create new file\n2.Delete a file\n3.Search for a file\n4.Display the files\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the new file name:");
                    scanf("%s",temp);
                    insert(temp);
                    break;
            
            case 2: printf("Enter the file name:");
                    scanf("%s",temp);
                    deleteF(temp);
                    break;
            
            case 3: printf("Enter the file name to be searched:");
                    scanf("%s",temp);
                    search(temp);
                    break;
            
            case 4: display();
                    break;
            
            case 5: printf("Exiting program!!!");
                    exitflag=true;
                    break;
            
        }
    }
        
}
