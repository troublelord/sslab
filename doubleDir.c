#include<stdio.h>
#include<string.h>
#define true 1
#define false 0

char Dtemp[10],Ftemp[10],dir[10][10],dirFile[10][10][10];
int Dcount=-1,Fcount[10];

void init(){
    for(int i=0;i<10;i++)
        Fcount[i]=-1;
    
}

int doesFileExist(int pos){
    for(int i=0;i<=Fcount[pos];i++){
     if(strcmp(dirFile[pos][i],Ftemp)==0){
            return 1;
        }
    }
    return 0;
}
int doesDirExist(){
    for(int i=0;i<=Dcount;i++){
        if(strcmp(dir[i],Dtemp)==0){
            return i;
        }
    }
    return -1;
}

void insert(){
    int dPos=doesDirExist();
    if(dPos!=-1){
        if(Dcount==9){
            printf("Memory full cannot create new directory !!\n");
            return;
        }
    	strcpy(dir[++Dcount],Dtemp);
    }
    if(doesFileExist(dPos)){
        printf("File %s already exists inside directory %s",Ftemp,Dtemp);
        return;
    }
    
    if(Fcount[dPos]==9){
        printf("Memory full cannot create new file !!\n");        
    }
    else{
        strcpy(dirFile[dPos][++Dcount]],Ftemp);
        printf("File %s successfully created\n",Ftemp);
    }
    
}

void deleteD(){
     int dPos=doesDirExist();
     if(dPos==-1){
         printf("Directory does not exist!!\n");
         return;
     }
     if(Fcount[dPos]==-1){
         strcpy(dir[dPos],dir[Dcount]);
         strcpy(dir[Dcount--],"")
     }
     else{
         printf("Cannot delete directory as it contains files");
     }
    
}

void deleteF(){
    int dPos=doesDirExist();
    if(!doesFileExist(dPos)){
        printf("File doesnt exist");
    }
    for(int i=0;i<=Fcount[dPos];i++){
        if(strcmp(dirFile[dPos][i],temp)==0){
            strcpy(dirFile[i],dirFile[count]);
            strcpy(dirFile[count--],"");
            return;
        }
    }
    
}
/*
void search(char temp[10]){
    for(int i=0;i<=count;i++){
        if(strcmp(dirFile[i],temp)==0){
            printf("File %s found in the directory\n",temp);  
            return;
        }
    }
    printf("File %s not found in the directory\n",temp);
}
*/

/*

void display(){
    for(int i=0;i<=count;i++){
        printf("%s\n",dirFile[i]);   
    }
    
}*/

void main(){
    int ch,exitflag=false;
    init();
    while(!exitflag){
        printf("1.Create new file\n2.Delete a file\n3.Search for a file\n4.Display the files\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the directory name:");
                    scanf("%s",Dtemp);
                    printf("Enter the new file name:");
                    scanf("%s",Ftemp);
                    insert();
                    break;
            
          /*  case 2: printf("Enter the directory name:");
                    scanf("%s",Dtemp);
                    printf("Enter the file name:");
                    scanf("%s",Ftemp);
                    deleteF(temp);
                    break;
            
            case 3:  printf("Enter the directory name:");
                    scanf("%s",Dtemp);
                    printf("Enter the file name to be searched:");
                    scanf("%s",Ftemp);
                    search(temp);
                    break;
            
            case 4: display();
                    break;*/
            
            case 5: printf("Exiting program!!!");
                    exitflag=true;
                    break;
            
        }
    }
        
}
