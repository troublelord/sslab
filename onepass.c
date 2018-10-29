#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char buf[25],a[10],b[10],c[10];
int locctr=0;
FILE *inf,*outf;


void onepass(){
	if(strcmp(b,"START")==0){
		if(strcmp(c,"")==0)
			locctr=0;
		else
			locctr = atoi(c);	
		fprintf(outf,"%d\n",locctr);
		return;
	}
	if(!strcmp(a,"")==0){
	
	//findsym();
	}
	else{
		
	}
	if(strcmp(b,"WORD")==0){
		locctr+=3;
	}
	else if(strcmp(b,"RESW")==0){
		locctr+=3*atoi(c);
	}
	else if(strcmp(b,"RESB")==0){
		locctr+=atoi(c);
	}
	else if(strcmp(b,"BYTE")==0){
		if(c[0]=='C')
			locctr+=strlen(c)-3;
		else
			locctr+=( (strlen(c)-3)%2==0?(strlen(c)-3)/2:(strlen(c)-3)/2+1  );
	}

	fprintf(outf,"%d\n",locctr);
	//printf("%d\n",locctr);
}

void split(){
	int i=0,x=0,y=0,z=0;
	strcpy(a,"");
	strcpy(b,"");
	strcpy(c,"");
	a[0]='\0';
	b[0]='\0';
	c[0]='\0';
	int lim=strlen(buf);
	for(;i<lim;i++){
		if(buf[i]!='\t'){
			a[x++]=buf[i];
			
			continue;
		}
		break;
		
	}
	a[x]='\0';
	
	//printf("%s\t",a);
	for(i++;i<lim;i++){
		if(buf[i]!='\t'){
			b[y++]=buf[i];
			
			continue;
		}
		
		break;
		
	}
	b[y]='\0';
	printf("%s",b);
	for(i++;i<lim;i++){
		if(buf[i]!='\t'){
			c[z++]=buf[i];			
			continue;
		}
		
		break;
		
	}
	c[z]='\0';
	//printf("%s\n",c);
	onepass();

}


void main(){
	
	inf = fopen("hi","r");
	outf = fopen("out","w");
    //int ku=0;
    do{
    	fscanf(inf,"%[^\n]s",buf); 
        //printf("%s\n", buf); 
        split();
        //ku++;
        fscanf(inf,"%c",buf);
        strcpy(buf,"");
        
	}while (!feof(inf));
	fclose(inf);
}
