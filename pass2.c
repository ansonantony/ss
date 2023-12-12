#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
    FILE *fp1,*fp2,*fp3,*fp4,*fp5;
    int start=0x0,locctr=0x0,endctr=0x0,length=0x0;
    char label[20],opcode[20],operand[20];
    char code[20],mneumonic[20];
    fp1 = fopen("inter.txt","r");
    fp2 = fopen("optab.txt","r");
    fp3 = fopen("symtab.txt","r");
    fp4 = fopen("objpgm.txt","w");
    fp5 = fopen("assmpgm.txt","w");
    fscanf(fp1,"%s%s%x\n",label,opcode,&start);
    while (strcmp(opcode,"END")!=0)
    {
            fscanf(fp1,"%x%s%s%s\n",&locctr,label,opcode,operand);
           
            endctr=locctr; //ending addr
           
    }

    rewind(fp1);
    fscanf(fp1,"%s%s%x\n",label,opcode,&start);
    //Header Record
    if (strcmp(opcode,"START")==0)
    {
        locctr=0x0+start;
        fprintf(fp5,"Hello");
        fprintf(fp5,"H %x %x\n",locctr,endctr);
        printf("H %x %x\n",locctr,endctr);
        fscanf(fp1,"%x%s%s%s\n",&locctr,label,opcode,operand);
    }
    length=endctr-start;
    fprintf(fp5,"T %x %x",start,length);
    printf("T %x %x",start,length);
    while (strcmp(opcode,"END")!=0)
    {
            fprintf(fp5," %x",locctr);
            printf(" %x",locctr);
            fscanf(fp1,"%x%s%s%s\n",&locctr,label,opcode,operand);
           
    }
    fprintf(fp5," %x",locctr);
            printf(" %x",locctr);
    fprintf(fp5,"\nE %x ",start);
    printf("\nE %x ",start);

    

}