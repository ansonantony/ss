#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
    FILE *fp1,*fp2,*fp3,*fp4;
    int start=0x0,locctr=0x0;
    char label[20],opcode[20],operand[20];
    char code[20],mneumonic[20];
    fp1 = fopen("input.txt","r");
    fp2 = fopen("optab.txt","r");
    fp3 = fopen("symtab.txt","w");
    fp4 = fopen("inter.txt","w");

    fscanf(fp1,"%s%s%x\n",&label,&opcode,&start);
    fprintf(fp4,"\t\t%s\t%s\t%x\n",label,opcode,start);
    printf("\t\t%s\t%s\t%x\n",label,opcode,start);
    if(strcmp(opcode,"START")==0){
        locctr=0x0+start;
        fscanf(fp1,"%s%s%s\n",label,opcode,operand);
        
    }
    while (strcmp(opcode,"END")!=0)
    {
       // locctr+=3;
        fprintf(fp4,"%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);
        printf("%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);

        if (strcmp(label,"**"))
        {
            fprintf(fp3,"%s\t%x\n",label,locctr);
        }

        fscanf(fp2,"%s%s",code,mneumonic);
        while (strcmp(code,"END")!=0)
        {
            if (strcmp(code,opcode)==0)
            {
                locctr+=3;
                break;
            }
            fscanf(fp2,"%s%s",code,mneumonic);
        }
        if(strcmp(opcode,"WORD")==0){
            locctr+=3;
        }
        if(strcmp(opcode,"RESW")==0){
            locctr+=3*atoi(operand);
        }
        if(strcmp(opcode,"RESB")==0){
            locctr+=atoi(operand);
        }
        if(strcmp(opcode,"BYTE")==0){
            ++locctr;
        }
        
        fscanf(fp1,"%s%s%s\n",label,opcode,operand);
    }
    fscanf(fp1,"%s%s%s\n",label,opcode,operand);
    fprintf(fp4,"%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);
    printf("%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);
    printf("%x",12);
}
