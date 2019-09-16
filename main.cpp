#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <wchar.h>
using namespace std;
#define printf ptcl
void ptcl(char str[]){
  char cmd[10000]={0,};
  strcpy(cmd,"echo ");
  strcat(cmd,str);
  system(cmd);
}
void change(wstring str);
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
  wifstream fp (flnm);
  wofstream tempf ("KorEaCtEmPfiLe.c");
  if(fp.fail()){
    printf("에러: 파일이 인식되지 않음");
    return 1;
  }
  wstring temp;
  while(getline(fp,temp)){
    change(temp);
    tempf<<temp<<endl;
  }
  tempf.close();
  system("gcc -o result.exe KorEaCtEmPfiLe.c");
  //remove("KorEaCtEmPfiLe.c");
  return 0;
}
void change(wstring str){
  for(int i=0;i<str.length();i++){
    if(str.compare(i,1,L"샵")==0){
      str.replace(i,1,L"#");
      printf("e");
    }
  }
}
