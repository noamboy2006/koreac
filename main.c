#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define printf ptcl
void ptcl(char str[]){
  char cmd[10000]={0,};
  strcpy(cmd,"echo ");
  strcat(cmd,str);
  system(cmd);
}
void change(char str[]);
int main(int argc,char *argv[]){
  if(argc<2){
    printf("에러: 파일명이 인식되지 않음");
    return 1;
  }
  char *flnm=argv[1];
  int fllg=strlen(flnm);
  if(fllg<=2){
    printf("에러: 파일 확장자가 잘못됨");
    return 1;
  }
  if(!(flnm[fllg-3]=='.'&&flnm[fllg-2]=='k'&&flnm[fllg-1]=='c')){
    printf("에러: 파일 확장자가 잘못됨");
    return 1;
  }
  FILE *fp;
  fp=fopen(flnm,"r");
  if(fp==NULL){
    printf("에러: 파일이 인식되지 않음");
    return 1;
  }
  FILE *tempf;
  tempf=fopen("KorEaCtEmPfiLe.c","w");
  do{
    char temp[2000]={0,};
    fscanf(fp,"%[^\n]",temp);
    change(temp);
    fprintf(tempf,"%s\n",temp);
  }while(fgetc(fp)!=EOF);
  fclose(tempf);
  system("gcc -o result.exe KorEaCtEmPfiLe.c");
  //remove("KorEaCtEmPfiLe.c");
  return 0;
}
void change(char str[]){
  for(int i=0;i<strlen(str);i++){
    if(str[i]=="샵"[0]){
      str[i]='#';
      for(int j=i+1;j<strlen(str);j++){
        str[j]=str[j+1];
      }
    }
  }
}
