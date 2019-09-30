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
    cout<<"에러: 파일명 또는 명령이 인식되지 않음"<<endl;
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
  if(argc<3){
    system("gcc -o result.exe KorEaCtEmPfiLe.c");
    remove("KorEaCtEmPfiLe.c");
    system("result.exe");
  }else if(argv[2][0]=='i'){
  }else if(argv[2][0]=='c'){
    system("gcc -o result.exe KorEaCtEmPfiLe.c");
    remove("KorEaCtEmPfiLe.c");
  }else if(argv[2][0]=='t'){
    system("gcc -o result.exe KorEaCtEmPfiLe.c");
    system("result.exe");
  }else if(argv[2][0]=='e'){
    system("gcc -o result.exe KorEaCtEmPfiLe.c");
    remove("KorEaCtEmPfiLe.c");
    system("result.exe");
  }
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
  map.push_back({"오우","o"});
  map.push_back({"에이치","h"});
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
  map.push_back({"대입","="});
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
  map.push_back({"쉼표",","});
  map.push_back({"그레이브액센트","`"});
  map.push_back({"물결","~"});
  map.push_back({"물음표","?"});
  map.push_back({"느낌표","!"});
  map.push_back({"점","."});
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
  map.push_back({"더블","double"});
  map.push_back({"구조체","struct"});
  map.push_back({"공용체","union"});
  map.push_back({"만약","if"});
  map.push_back({"열거형","enum"});
  map.push_back({"반복","while"});
  map.push_back({"포","for"});
  map.push_back({"해라","do"});
  map.push_back({"인클루드","include"});
  map.push_back({"디파인","define"});
  map.push_back({"출력","printf"});
  map.push_back({"입력","scanf"});
  map.push_back({"스위치","switch"});
  map.push_back({"케이스","case"});
  map.push_back({"브레이크","break"});
  map.push_back({"컨티뉴","continue"});
  map.push_back({"리턴","return"});
  map.push_back({"에이","a"});
  map.push_back({"비","b"});
  map.push_back({"시","c"});
  map.push_back({"디","d"});
  map.push_back({"이","e"});
  map.push_back({"에프","f"});
  map.push_back({"쥐","g"});
  map.push_back({"아이","i"});
  map.push_back({"제이","j"});
  map.push_back({"케이","k"});
  map.push_back({"엘","l"});
  map.push_back({"엠","m"});
  map.push_back({"엔","n"});
  map.push_back({"피","p"});
  map.push_back({"큐","q"});
  map.push_back({"얼","r"});
  map.push_back({"에스","s"});
  map.push_back({"티","t"});
  map.push_back({"유","u"});
  map.push_back({"브이","v"});
  map.push_back({"더블유","w"});
  map.push_back({"엑스","x"});
  map.push_back({"와이","y"});
  map.push_back({"제트","z"});
}
