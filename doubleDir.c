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
<<<<<<< HEAD
    if(dPos==-1){
=======
    if(dPos!=-1){
>>>>>>> 610b259d27ddcfe4fdb64ab71d1e150e86174998
        if(Dcount==9){
            printf("Memory full cannot create new directory !!\n");
            return;
        }
    	strcpy(dir[++Dcount],Dtemp);
<<<<<<< HEAD
    	dPos=Dcount;
    }
    if(doesFileExist(dPos)){
        printf("File %s already exists inside directory %s!!\n",Ftemp,Dtemp);
=======
    }
    if(doesFileExist(dPos)){
        printf("File %s already exists inside directory %s",Ftemp,Dtemp);
>>>>>>> 610b259d27ddcfe4fdb64ab71d1e150e86174998
        return;
    }
    
    if(Fcount[dPos]==9){
        printf("Memory full cannot create new file !!\n");        
    }
    else{
<<<<<<< HEAD
        strcpy(dirFile[dPos][++Fcount[dPos]],Ftemp);
=======
        strcpy(dirFile[dPos][++Dcount],Ftemp);
>>>>>>> 610b259d27ddcfe4fdb64ab71d1e150e86174998
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
         strcpy(dir[Dcount--],"");
<<<<<<< HEAD
         printf("Directory %s successfully deleted\n",Dtemp);
=======
>>>>>>> 610b259d27ddcfe4fdb64ab71d1e150e86174998
     }
     else{
         printf("Cannot delete directory as it contains files");
     }
    
}

void deleteF(){
    int dPos=doesDirExist();
<<<<<<< HEAD
    if(dPos==-1){
    	printf("The directory %s doesnt not exist !!\n",Dtemp);
    	return;
    }
    if(!doesFileExist(dPos)){
        printf("File doesnt exist");
        return;
    }
    for(int i=0;i<=Fcount[dPos];i++){
        if(strcmp(dirFile[dPos][i],Ftemp)==0){
            strcpy(dirFile[dPos][i],dirFile[dPos][Fcount[dPos]]);
            strcpy(dirFile[dPos][Fcount[dPos]--],"");
            return;
        }
    }
}

void display(){
	int temp=Dcount;
	while(temp>-1){
		printf("%s\n",dir[temp]);
		for(int i=0;i<=Fcount[temp];i++){
			printf("\t --->%s\n",dirFile[temp][i]);
		}
		temp--;
	}
}
void search(){
    int dPos=doesDirExist();
    if(dPos==-1){
    	printf("The directory %s doesnt not exist !!\n",Dtemp);
    	return;
    }
    if(!doesFileExist(dPos)){
        printf("File %s not found in the %s directory\n",Ftemp,Dtemp);
        return;
    }
    else{
    	 printf("File %s found in the %s directory\n",Ftemp,Dtemp);
    }
}
=======
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
>>>>>>> 610b259d27ddcfe4fdb64ab71d1e150e86174998

void main(){
    int ch,exitflag=false;
    init();
    while(!exitflag){
<<<<<<< HEAD
        printf("1.Create new file\n2.Delete a directory\n3.Delete a file\n4.Search for a file\n5.Display the files\n6.Exit Program\n");
=======
        printf("1.Create new file\n2.Delete a file\n3.Search for a file\n4.Display the files\n");
>>>>>>> 610b259d27ddcfe4fdb64ab71d1e150e86174998
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the directory name:");
                    scanf("%s",Dtemp);
                    printf("Enter the new file name:");
                    scanf("%s",Ftemp);
                    insert();
                    break;
            
<<<<<<< HEAD
            case 2: printf("Enter the directory name:");
                    scanf("%s",Dtemp);
                    deleteD();
                    break;
                    
            case 3: printf("Enter the directory name:");
                    scanf("%s",Dtemp);
            	    printf("Enter the file name:");
                    scanf("%s",Ftemp);
                    deleteF();
                    break;
            
            case 4: printf("Enter the directory name:");
                    scanf("%s",Dtemp);
                    printf("Enter the file name to be searched:");
                    scanf("%s",Ftemp);
                    search();
                    break;
            
            case 5: display();
                    break;
            
            case 6: printf("Exiting program!!!");
=======
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
>>>>>>> 610b259d27ddcfe4fdb64ab71d1e150e86174998
                    exitflag=true;
                    break;
            
        }
    }
        
}
