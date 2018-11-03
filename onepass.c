#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int symcount=0,END=0;
char buf[25],a[10],b[10],c[10];
int locctr=0;
FILE *inf,*outf, *sym;

struct OPMAP{
	char OP[5];
	char HEX[2];
};

struct SYMMAP{
	char OP[5];
	char HEX[4];
};

struct SYMMAP SYMTAB[20];

struct OPMAP OPTAB[26]={
	"ADD","18",
	"AND","40",
	"COMP","28",
	"DIV","24",
	"J","3C",
	"JEQ","30",
	"JGT","34",
	"JLT","38",
	"JSUB","48",
	"LDA","00",
	"LDCH","50",
	"LDL","08",
	"LDX","04",
	"MUL","20",
	"OR","44",
	"RD","D8",
	"RSUB","4C",
	"STA","0C",
	"STCH","54",
	"STL","14",
	"STSW","E8",
	"STX","10",
	"SUB","1C",
	"TD","E0",
	"TIX","2C",
	"WD","DC"
};
//int startadd=0;

void onepass(){
	if(strcmp(b,"START")==0){
		if(strcmp(c,"")==0)
			locctr=0;
		else{
			int temp = atoi(c),i=0,mul=1;
			while(temp>0){
				locctr+=(temp%10) * mul;
				temp=temp/10;
				mul*=16;
			}
		}	
		fprintf(outf,"%X",locctr);
		fprintf(outf,"\t%s\t%s\n",b,c);
		//startadd=locctr;
		return;
	}
	fprintf(outf,"%X",locctr);
	fprintf(outf,"\t%s\t%s\n",b,c);
	int flagsym=0;
	if(!strcmp(a,"")==0){
		for(int i=0;i<symcount;i++){
			if(strcmp(SYMTAB[i].OP,a)==0){
				printf("ERROR");
				return;
			}
		}
		strcpy(SYMTAB[symcount].OP,a);
		fprintf(sym,"%s\t%X\n",a,locctr);
		char temp[5];
		sprintf(temp,"%d",locctr);
		strcpy(SYMTAB[symcount++].HEX,temp);
	
	}
	int flagop=0;
	for(int i=0;i<26;i++){
			if(strcmp(OPTAB[i].OP,b)==0){
				flagop=1;
				break;
			}
		}
	if(flagop){
		locctr+=3;
	}
	else if(strcmp(b,"WORD")==0){
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
	//printf("%s",b);
	for(i++;i<lim;i++){
		if(buf[i]!='\t'){
			c[z++]=buf[i];			
			continue;
		}
		
		break;
		
	}
	c[z]='\0';
	//printf("%s\n",c);
	if(strcmp(b,"END")!=0 )
		onepass();
	else{
		//endadd=locctr;
		
		END=1;
		fprintf(outf,"%X",locctr);
		fprintf(outf,"\t%s\t%s\n",b,c);
	}

}


void main(){
	inf = fopen("input","r");
	outf = fopen("out","w");
	sym=fopen("symtab","w");
    do{
    	fscanf(inf,"%[^\n]s",buf); 
	if(buf[0]!='.' && !END)
        	split();
        fscanf(inf,"%c",buf);
        strcpy(buf,"");
        
	}while (!feof(inf));
	fclose(inf);
	fclose(outf);
	fclose(sym);
}
