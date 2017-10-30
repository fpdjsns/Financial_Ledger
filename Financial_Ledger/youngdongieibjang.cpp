#include<iostream>
#include<stdio.h>
#include <string>
#include <iomanip>
#include<time.h>
#include<conio.h>//_kbhit(),_getch()
#include<Windows.h>//gotoxy 함수
#include"user.h"
#pragma warning(disable: 4996)

using namespace std;

struct userinfo{

	string name;//이름
	string 생년월일;
	string 전화번호;
	string month;//월

};

void printstart();  //프로그램 시작화면 출력 함수.
void clean_screen();
void gotoxy(int x,int y);
void bling(char *str,int x,int y);
int get_key();


void printstart(){   

   

   cout<<"==========================================================================\n";
   cout<<"==========================================================================\n";
   cout<<"===        ===============================================================\n";
   cout<<"===  ===============          ==========     ========            ==  =====\n";
   cout<<"===  ===============  ======  =========  ===  =======            ==  =====\n";
   cout<<"===  ===============  ======  ========  =====  ==========    ======  =====\n";
   cout<<"===        =========  ======  =======  =======  =========    ======  =====\n";
   cout<<"====================  ======  ======  =========  ========    ======  =====\n";
   cout<<"======  ============  ======  ======  =========  ========    ======  =====\n";
   cout<<"======  ============  ======  =======  =======  =========    ======     ==\n";
   cout<<"==            ======  ======  ========  =====  ==========    ======  =====\n";
   cout<<"====================          =========  ===  ==========  ==  =====  =====\n";
   cout<<"===  ===================================    ===========  ===   ====  =====\n";
   cout<<"===  ==================  =============================  =====  ====  =====\n";
   cout<<"===  ==================  =============================  ======  ===  =====\n";
   cout<<"===  ==================  ============================  ========  ==  =====\n";
   cout<<"===          =====              ===               =================  =====\n";
   cout<<"==========================================================================\n";
   cout<<"==========================================================================\n";
   cout<<"==========================================================================\n";
   cout<<"==========================================================================\n";
   cout<<"==========================================================================\n";
   cout<<"==============================       =====================================\n";
   cout<<"==========================================================================\n";

   int key=0;
  
   bling("ENTER",31,22);
   clean_screen();//화면 지우기
} //프로그램 시작화면 출력 함수.

void clean_screen(){
   int y,x;
   for(y=0;y<30;y++)
      for(x=0;x<80;x++){
         gotoxy(x,y);
         putch(' ');
      }
   gotoxy(0,0);
}//화면 지우기

void gotoxy(int x,int y){
   COORD pos={x,y};

   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}//커서 위치옮기기




void bling(char *str,int x,int y){
   int time=clock();
   char key=0;

  
   gotoxy(x,y);
   cout<< str;
      

   key=0;
   while(key!=13){//무한반복
      if(clock()-time==1300){
         gotoxy(x,y);
         cout<< str;
      }
      if(clock()-time>=2000){
         gotoxy(x,y);
         for(int i=0;i<strlen(str); i++)
            cout<<" ";
         time=clock();
      }

      key=get_key();
   
   }
}//문자 깜빡임

int get_key(){ 
   int key=0;   //키를 누르지 않았다고 가정
   if(_kbhit())  //사용자가 키를 눌렀을 때
      key=_getch(); //키를 읽고
   return key;   //리턴
}//입력 키 인식

inline int printmenu(){   
   cout<<"\n";
   

   cout<<"==========================================================================\n";
    cout<<"==========================================================================\n";
   gotoxy(34,6); cout<<"메뉴 선택.";
   gotoxy(29,9); cout<<"1. 사용자 정보입력"; 
   gotoxy(29,10); cout<<"2. 지출날짜 정보입력";
   gotoxy(29,11); cout<<"3. 수정하기";
   gotoxy(29,12); cout<<"4. 날짜별 지출내역";
   gotoxy(29,13); cout<<"5. 전제 지출내역보기";
   gotoxy(29,14); cout<<"6. 사용자 정보 보기";
   gotoxy(29,15); cout<<"7. 종료";
    gotoxy(38,17); cout<<"<-";
   gotoxy(0,22);
   

   cout<<"==========================================================================\n";
   cout<<"==========================================================================\n";


   int num;
   gotoxy(36,17);
   cin>>num;

   clean_screen();

   return num; //난이도 반환
}//난이도 출력화면 함수.



int main(){
	system("mode con: lines=25 cols=76");
	//
	//user us;//사용자클래스

	//us.Initialize();
	//us.InputData();
	//us.PrintTitle();
	//us.PrintData();

	 printstart();  //시작화면 출력
    




	 userinfo us;
	 user us1;

	 for(;;){
	 int select=printmenu(); //난이도 선택

	 if(select==1){
		 
		 cout<<"==========================================================================\n";
    
		 cout<<"\n           이름을 입력하시오 : ";
		 cin>>us.name;
		 us1.Get(us.name);
		 cout<<"           생년월일을 입력하시오 : ";
		 cin>>us.생년월일;
		  cout<<"           전화번호를 입력하시오 : ";
		  cin>>us.전화번호;
		  cout<<"           현재 월을 입력하시오 : ";
		  cin>>us.month;
		 cout<<"\n==========================================================================\n";

		cin.ignore();
	    cout<<"\n\n메뉴로 돌아가려면 아무키나 입력하시오";
		cin.ignore();
		 char key=0;
		 key=get_key();
		 clean_screen();
	 }

	 if(select==2 ){

		 
		 us1.InputData();

	     clean_screen();

		 
	 }

	 if(select==3 ){

		 int num;
		 
		 cout<<"======================================\n";
		 cout<<"    어떤 정보를 수정하시겠습니까?\n";
		 cout<<"         1. 사용자 정보\n";
		 cout<<"         2. 날짜 정보 \n";
		 cout<<"         3. 물건 정보 \n";
		 cout<<"======================================\n\n";

		 cin>>num;
		 switch(num){

		 case 1:
		    us1.Modify();
		 break;

		 case 2:
			 day* num1;
			 num1=us1.daySearch();
			 num1->Modify();

			 //us1.m_dday[num].Modify();

			 break;

		 case 3:

			 day* num2;
			 object* obj;
			 num2=us1.daySearch();

			 obj=num2->objectSearch();
			 obj->Modify();
			
			break;
			

		 }
			cin.ignore();
	    cout<<"메뉴로 돌아가려면 아무키나 입력하시오";
		cin.ignore();
		 char key=0;
		 key=get_key();
		 clean_screen();
		
	 }

	if(select==4 ){
		 day* num3;
		  cout<<"=======================================================================\n";
		 cout<<"               "<<us.name<<"님의 "<<us.month<<" 지출내역 \n ";
		 cout<<"========================================================================\n";
		 cout<<"\n\n 찾으시는 날짜를 입력하세요. \n";
	   num3 = us1.daySearch();
	   if(num3!=NULL)
			num3->PrintData();
	   else
		   cout<<"찾으시는 날짜를 찾을 수 없습니다.\n";
    	cin.ignore();
	    cout<<"메뉴로 돌아가려면 아무키나 입력하시오";
		cin.ignore();
		 char key=0;
		 key=get_key();
		 clean_screen();
	}

	if(select==5 ){
		 cout<<"==========================================================================\n";
		 cout<<"               "<<us.name<<"님의 "<<us.month<<" 지출내역 \n ";
		 cout<<"==========================================================================\n";
		 
		 us1.Print();

		cin.ignore();
	    cout<<"메뉴로 돌아가려면 아무키나 입력하시오";
		cin.ignore();
		 char key=0;
		 key=get_key();
		 clean_screen();
	 }
	if(select==6){
		 cout<<"==========================================================================\n";
		 cout<<"                      "<<us.name<<"님의 정보 \n ";
		 cout<<"==========================================================================\n";

		 cout<<"         생년월일 : "<< us.생년월일;
		 cout<<"         전화번호 : "<< us.전화번호;
		
		 cout<<"\n\n";

		 cin.ignore();
	    cout<<"메뉴로 돌아가려면 아무키나 입력하시오";
		cin.ignore();
		 char key=0;
		 key=get_key();
		 clean_screen();
	}
	if(select==7)
		break;
	 }
	return 0;
}