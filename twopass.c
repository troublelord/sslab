#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int symcount=0,END=0,ku=0,firsttext=0;
char buf[40],symbuf[40],a[20],b[20],c[20],line[100];//,d[10];
//int locctr=0;
FILE *inf,*outf, *sym;

struct OPMAP{
	char OP[5];
	char HEX[3];
};

struct SYMMAP{
	char OP[10];
	char HEX[6];
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

void loadsymtab(){
	sym=fopen("symtab","r");
	if(sym!=NULL){
	do{
	
		//printf("hi2");
	   int x=0,y=0;
    	   fscanf(sym,"%[^\n]s",symbuf); 
	   //if(buf[0]!='.' && !END)
	strcpy(a,"");
	strcpy(b,"");
	a[0]='\0';
	b[0]='\0';
	int i=0,lim=strlen(symbuf);
	for(;i<lim;i++){
		if(symbuf[i]!='\t'){
			a[x++]=symbuf[i];
			//printf("hi3");
			
			continue;
		}
		break;
		
	}
	a[x]='\0';
	//x=0;
	strcpy(SYMTAB[symcount].OP,a);
	
	
	//printf("%s\t",a);
	for(i++;i<lim;i++){
		if(symbuf[i]!='\t'){
			b[y++]=symbuf[i];
			
			continue;
		}
		
		break;
		
	}
	b[y]='\0';
	y=0;
	strcpy(SYMTAB[symcount++].HEX,b);
     	   fscanf(sym,"%c",symbuf);
     	   strcpy(symbuf,"");
	
        
	}while (!feof(sym));}
	//fclose(sym);
}	



int tlen=0,reset=0;
long curr_pos=0,prev_pos=0;
char header1[50],header2[50], text1[50],text2[50], startadd[10],endadd[10];



void lengthprint(){
	char hii[50];
	FILE *inff;
	char temp3[20],temp2[20];
	inff = fopen("out","r");
	do{
    		fscanf(inff,"%[^\n]s",hii); 
        		int lim=strlen(hii),i=0,x=0,y=0;
		for(;i<lim;i++){
			if(hii[i]!='\t'){
				temp2[x++]=hii[i];
			
				continue;
			}
			break;
		
		}
	
		temp2[x]='\0';
	
		//printf("%s\t",a);
		for(i++;i<lim;i++){
			if(hii[i]!='\t'){
				temp3[y++]=hii[i];
			
				continue;
			}
			
			break;
			
		}
		temp3[y]='\0';
		if(strcmp(temp3,"END")==0){
			strcpy(endadd,temp2);
		
			
			break;
	
		}
        	fscanf(inff,"%c",hii);
        	strcpy(hii,"");
        
	}while (!feof(inff));
	fclose(inff);


}

void twopass(){
	//printf("%s %X %s\n",text1,tlen,text2);
	if(strcmp(b,"START")==0){
		strcpy(startadd,a);
		FILE *prog;
		char temp[10];
		prog=fopen("input","r");
		fscanf(prog,"%[^\t]s",temp);
		fclose(prog);
		//sprintf(header1,"H^%s^%s^\n",temp,a);


		int i=strlen(a);char zero[]="0", zeroo[6];
						strcpy(zeroo,"");
						while(i<6){
							strcat(zeroo,zero);
							i++;
						}
		lengthprint();
		int num1 = (int)strtol(startadd, NULL, 16);
		int num2 = (int)strtol(endadd, NULL, 16);
		num2=num2-num1;

		fprintf(outf,"H^%-6s^%s%s^%06X\n",temp,zeroo,a,num2);
		//fprintf(outf,"T");
		firsttext=1;
		sprintf(text1,"T");
		//prev_pos=ftell(outf)+2;
		return;
	}
	
	int opflag=0,symflag=0,opind=0,symind=0,flagindex=0;
	char opadd1[10]="00",opadd2[10]="0000",str[20],ctemp[20];
	for(;opind<26;opind++){
		if(strcmp(OPTAB[opind].OP,b)==0){
			opflag=1;
			strcpy(header1,"");
			//printf("%d current position ",);
			//printf("%s1\n",b);
			strcpy(opadd1,OPTAB[opind].HEX);
			break;
		}
	}
	if(strcmp("RESW",b)==0 || strcmp("RESB",b)==0  ){
		if(tlen!=0){
					char temp[50];
					char len[5];
					sprintf(len,"%X",tlen);
					strcat(text1,len);
					strcat(text1,text2);
					fprintf(outf,"%s",text1);
					//strcpy(temp,"");
					strcpy(text1,""); 
					strcpy(text2,""); 
					tlen=0;
					//firsttext=1;
					sprintf(text1,"\nT^");
					reset=1;
		}
		else	
			return;
		
	}
	else if(opflag==1){
		if(c[0]!='\0'){
			for(int i=0;i<symcount;i++){
				int k=0;
				for(;k<strlen(c);k++){
					
					if(c[k]==','){
						
						flagindex=1;
						break;
						
					}
					ctemp[k]=c[k];
					
				}
				ctemp[k]='\0';
				
				if(!flagindex){
					if(strcmp(SYMTAB[i].OP,c)==0){
						symflag=1;
						strcpy(opadd2,SYMTAB[i].HEX);
						break;
					}
				}
				else{	
					if(strcmp(SYMTAB[i].OP,ctemp)==0){
						char ch[10],ophex[10];
						strcpy(ophex,SYMTAB[i].HEX);
								int t=0,t2=0,mul=1;
						for(int q=strlen(ophex)-1;q>=0;q--){
							strcpy(ch,"");
	   						sprintf(ch,"%c",ophex[q]);
						//printf("%c ",ophex[q]);
	   						 switch(ch[0]){


							case '1':t2+=1 * mul;
								break;
							case '2':t2+=2 * mul;
								break;

							case	'3':t2+=3 * mul;
								break;


	
							case	'4':t2+=4 * mul;
								break;



							case	'5':t2+=5 * mul;
								break;



							case	'6':t2+=6 * mul;
								break;



							case	'7':t2+=7 * mul;
								break;



							case	'8':t2+=8 * mul;
								break;



							case	'9':t2+=9 * mul;
								break;

							case	'A':t2+=10 * mul;
								break;



							case	'B':t2+=11 * mul;
								break;



							case	'C':t2+=12 * mul;
									break;



							case	'D':t2+=13 * mul;
								break;



							case	'E':t2+=14 * mul;
									break;



							case	'F':t2+=15 * mul;
							        break;

							}

							mul*=16;
						}
						strcpy(ch,"");
	   					sprintf(ch,"%X",t2+32768);
							//printf("%d",t2);
						strcpy(opadd2,ch);
							
					
							break;
					}

				}
			}
			//if(symflag==1){
				if(tlen+3<=30){
					char temp[50];
					tlen+=3;
					if(reset){int i=strlen(a);char zero[]="0";
						while(i<6){
							strcat(text1,zero);
							i++;
						}
						strcat(text1,a);strcat(text1,"^");
						reset=0;
					}
					sprintf(temp,"^%s%s",opadd1,opadd2);  
					if(firsttext){
						strcat(text1,"^");
						int i=strlen(a);char zero[]="0";
						while(i<6){
							strcat(text1,zero);
							i++;
						}
						strcat(text1,a);
						strcat(text1,"^");     
						firsttext=0;
					}   
					strcat(text2,temp);
					//fprintf(outf,"^%s%s",opadd1,opadd2);                                              //HERE HERE HERE HERE
				}
				else{
					
					char temp[50];
					char len[5];
					sprintf(len,"%X",tlen);
					strcat(text1,len);
					strcat(text1,text2);
					fprintf(outf,"%s",text1);
					//strcpy(temp,"");
					strcpy(text1,""); 
					strcpy(text2,"");
					sprintf(text1,"\nT^");					
					 int i=strlen(a);char zero[]="0";
						while(i<6){
							strcat(text1,zero);
							i++;
						}
					sprintf(temp,"%s^",a);
					strcat(text1,temp);
					//sprintf(text1,"\nT^%s^",a);
					sprintf(text2,"^%s%s",opadd1,opadd2);    
					    
					//strcat(line,temp);
					tlen=0;
					tlen+=3;
					
				}
			//}
		}
		else{
			if(tlen+3<=30){
					char temp[50];
					tlen+=3;
					if(reset){int i=strlen(a);char zero[]="0";
						while(i<6){
							strcat(text1,zero);
							i++;
						}
						strcat(text1,a);strcat(text1,"^");
						reset=0;
					}
					sprintf(temp,"^%s%s",opadd1,opadd2);           
					strcat(text2,temp);
				}
				else{
					char temp[50];
					char len[5];
					sprintf(len,"%X",tlen);
					strcat(text1,len);
					strcat(text1,text2);
					fprintf(outf,"%s",text1);
					//strcpy(temp,"");
					strcpy(text1,""); 
					strcpy(text2,""); 
					sprintf(text1,"\nT^");					
					 int i=strlen(a);char zero[]="0";
						while(i<6){
							strcat(text1,zero);
							i++;
						}
					sprintf(temp,"%s^",a);
					strcat(text1,temp);
					//sprintf(text1,"\nT^%s^",a);
					sprintf(text2,"^%s%s^",opadd1,opadd2);    
					tlen=0;
					tlen+=3;
				}
		}
	}
	else if(strcmp("BYTE",b)==0  ){
		
		int len=strlen(c);
		if(c[0]=='C'){
			int i=2;
			strcpy(str,"");
			char temp[5];
			while(i<len-1){
				sprintf(temp,"%X",c[i]);
				sprintf(temp,"%s",temp);
				//sprintf(temp,"%d",c[i]);
				strcat(str,temp);
				//strcat(str,"\0");
				i++;

			}
			printf("%s  ",str);
			//strcat(str,"\0");
	
		if(tlen+strlen(str)<=30){
					char temp[12];
					int clen=strlen(str);
					clen=clen%2==0?clen/2:clen/2+1;
					tlen+=clen;
					if(reset){int i=strlen(a);char zero[]="0";
						while(i<6){
							strcat(text1,zero);
							i++;
						}
						strcat(text1,a);strcat(text1,"^");
						reset=0;
					}
					sprintf(temp,"^%s",str);
					strcat(text2,temp);
					//printf("%s",temp);
					
				}
				else{
					char temp[50];
					char len[5];
					sprintf(len,"%X",tlen);
					strcat(text1,len);
					strcat(text1,text2);
					fprintf(outf,"%s",text1);
					//strcpy(temp,"");
					strcpy(text1,""); 
					strcpy(text2,"");
					sprintf(text1,"\nT^");					
					 int i=strlen(a);char zero[]="0";
						while(i<6){
							strcat(text1,zero);
							i++;
						}
					sprintf(temp,"%s^",a);
					strcat(text1,temp);					
					//sprintf(text1,"\nT^%s^",a);
					sprintf(text2,"^%s",str);
					tlen=0;
					tlen+=strlen(str);
				}
			
		}
		else{
			int i=2;
			strcpy(str,"");
			for(;i<len-1;i++){
				str[i-2]=c[i];
			}
			str[i-2]='\0';printf("%s  ",str);
			int clen=strlen(str);
			clen=clen%2==0?clen/2:clen/2+1;
			if(tlen+clen<=30){
					char temp[12];
					tlen+=clen;
					if(reset){int i=strlen(a);char zero[]="0";
						while(i<6){
							strcat(text1,zero);
							i++;
						}
						strcat(text1,a);strcat(text1,"^");
						reset=0;
					}
					sprintf(temp,"^%s",str);
					strcat(text2,temp);
					
				}
				else{
					char temp[50];
					char len[5];
					sprintf(len,"%X",tlen);
					strcat(text1,len);
					strcat(text1,text2);
					fprintf(outf,"%s",text1);
					//strcpy(temp,"");
					strcpy(text1,""); 
					strcpy(text2,"");
					sprintf(text1,"\nT^");					
					 int i=strlen(a);char zero[]="0";
						while(i<6){
							strcat(text1,zero);
							i++;
						}
					sprintf(temp,"%s^",a);
					strcat(text1,temp);
					//sprintf(text1,"\nT^%s^",a);
					sprintf(text2,"^%s",str);
					tlen=0;
					tlen+=clen;
				}
		}
		
	}
	else if(strcmp("WORD",b)==0){
		char t[7],temp[7]="000000";
		int y=strlen(c),z=0;
		while(y<6){
			t[z]=temp[z];z++;y++;
;		}
		t[z]='\0';
		strcat(t,c);
		if(tlen+3<=30){
				
			tlen+=3;
			if(reset){int i=strlen(a);char zero[]="0";
						while(i<6){
							strcat(text1,zero);
							i++;
						}
				strcat(text1,a);strcat(text1,"^");
				reset=0;
			}
			strcat(text2,"^");
			strcat(text2,t);
			//printf("%s",t);
			//printf(" %X ",tlen);
			//fprintf(outf,"^%s",t);
		}
		else{	
			char temp[50];
					
			char len[5];
			sprintf(len,"%X",tlen);
			strcat(text1,len);
			strcat(text1,text2);
			fprintf(outf,"%s",text1);
			strcpy(text1,"");strcpy(text2,"");
			sprintf(temp,"\nT^%s^",a);
			strcat(text1,temp);	
			sprintf(text2,"^%s",t);
			tlen=0;
			tlen+=3;
		}
	}
	
}



void split(){
	int i=0,x=0,y=0,z=0;
	strcpy(a,"");
	strcpy(b,"");
	strcpy(c,"");
	//strcpy(d,"");
	a[0]='\0';
	b[0]='\0';
	c[0]='\0';
	//d[0]='\0';
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
	//printf("%s\t",b);
	for(i++;i<lim;i++){
		if(buf[i]!='\t'){
			c[z++]=buf[i];			
			continue;
		}
		
		break;
		
	}
	c[z]='\0';
	//printf("%s\n",c);
	/*for(i++;i<lim;i++){
		if(buf[i]!='\t'){
			c[x++]=buf[i];
			
			continue;
		}
		break;
		
	}
	d[x]='\0';*/
	if(strcmp(b,"END")!=0 ){
		
		twopass();
	}
	else{
		END=1;
		
		char temp[50];
		char len[5];
		sprintf(len,"%X",tlen);
		strcat(text1,len);
		strcat(text1,text2);
		fprintf(outf,"%s",text1);
		//strcpy(temp,"");
		strcpy(text1,""); 
		strcpy(text2,""); fprintf(outf,"\nE^");
		int i=strlen(startadd);char zero[]="0";
						while(i<6){
							fprintf(outf,"0");
							i++;
						}
		fprintf(outf,"%s",startadd);
		//fprintf(outf,"%X",locctr);
		//fprintf(outf,"\t%s\t%s\n",b,c);
	}

}


void main(){
	
	
	
	
	loadsymtab();
	inf = fopen("out","r");
	outf = fopen("obj","w");
    do{
    	fscanf(inf,"%[^\n]s",buf); 
	if(buf[0]!='.' && !END)
        	split();
        fscanf(inf,"%c",buf);
        strcpy(buf,"");
        
	}while (!feof(inf));
	fclose(inf);
	fclose(outf);
	//fclose(sym);
}
