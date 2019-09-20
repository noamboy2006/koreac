#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
string change(string input);
void init();
vector<pair<string,string>> map;
int main(int argc,char *argv[]){
  cout.flush();
  if(argc<2){
    cout<<"에러: 파일명이 인식되지 않음"<<endl;
    return 1;
  }
  char *flnm=argv[1];
  int fllg=strlen(flnm);
  if(fllg<=2){
    cout<<"에러: 파일 확장자가 잘못됨"<<endl;
    return 1;
  }
  if(!(flnm[fllg-3]=='.'&&flnm[fllg-2]=='k'&&flnm[fllg-1]=='c')){
    cout<<"에러: 파일 확장자가 잘못됨"<<endl;
    return 1;
  }
  ifstream fp (flnm);
  ofstream tempf ("KorEaCtEmPfiLe.c");
  if(fp.fail()){
    cout<<"에러: 파일이 인식되지 않음"<<endl;
    return 1;
  }
  string temp;
  init();
  while(getline(fp,temp)){
    temp=change(temp);
    tempf<<temp<<endl;
  }
  tempf.close();
  //system("gcc -o result.exe KorEaCtEmPfiLe.c");
  //remove("KorEaCtEmPfiLe.c");
  return 0;
}
string change(string input){
  string str=input;
  for (int i = 0; i < str.size(); i++) {
    for (int j = 0; j < map.size(); j++) {
      if(str.compare(i,map[j].first.size(),map[j].first)==0){
        str.replace(i,map[j].first.size(),map[j].second);
      }
    }
  }
  return str;
}
void init(){
  //기호
  map.push_back({"큰따옴표","\""});
  map.push_back({"작은따옴표","\'"});
  map.push_back({"여는소괄호","("});
  map.push_back({"닫는소괄호",")"});
  map.push_back({"여는중괄호","{"});
  map.push_back({"닫는중괄호","}"});
  map.push_back({"여는대괄호","["});
  map.push_back({"닫는대괄호","]"});
  map.push_back({"여는제목","<"});
  map.push_back({"닫는제목",">"});
  map.push_back({"작다","<"});
  map.push_back({"크다",">"});
  map.push_back({"같다","="});
  map.push_back({"샵","#"});
  map.push_back({"퍼센트","%"});
  map.push_back({"세미콜론",";"});
  map.push_back({"콜론",":"});
  map.push_back({"달러","$"});
  map.push_back({"슬래쉬","/"});
  map.push_back({"역슬래쉬","\\"});
  map.push_back({"앤드","&"});
  map.push_back({"곱하기","*"});
  map.push_back({"더하기","+"});
  map.push_back({"뺴기","-"});
  map.push_back({"나누기","/"});
  map.push_back({"별","*"});
  map.push_back({"느낌표","!"});
  map.push_back({"꺽쇠","^"});
  map.push_back({"하이픈","-"});
  map.push_back({"언더바","_"});
  map.push_back({"또는","|"});
  map.push_back({"영","0"});
  map.push_back({"일","1"});
  map.push_back({"이","2"});
  map.push_back({"삼","3"});
  map.push_back({"사","4"});
  map.push_back({"오","5"});
  map.push_back({"육","6"});
  map.push_back({"칠","7"});
  map.push_back({"팔","8"});
  map.push_back({"구","9"});
  map.push_back({"긴","long"});
  map.push_back({"작은","short"});
  map.push_back({"문자","char"});
  map.push_back({"정수","int"});
  map.push_back({"실수","float"});
  map.push_back({"구","9"});

  map.push_back({"인클루드","include"});
  map.push_back({"정수","int"});
}
