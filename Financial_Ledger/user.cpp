#include <iostream>
#include <string>
#include <iomanip>
#include "user.h"
#include "InputUtil.h"


;using namespace std;


void user:: InputData(){
   //cin.ignore();
  // cout << "사용자명: ";
  // InputUtil:: InputValue(m_name);
	cout<<"==========================================================================\n\n";
   cout << "         용돈 : ";
   InputUtil::InputValue(m_allow);
   cout << "         소비한 날짜 수 : ";
   InputUtil::InputValue(m_day_num);
   cout<<"\n===========================================================================\n\n";
   cout << "\n";

   m_dday=new day[m_day_num]; //동적할당

   int i;
   for(i=0;i<m_day_num;i++)
      m_dday[i].InputData();

    Calc();//계산
}//일반멤버변수 값 입력


void user:: PrintTitle()const{
   cout << "================================================\n";
   cout << "     이름       용돈    총지출액      남은 돈\n";        //안내문 출력.
   cout << "================================================\n";
}//일반멤버변수 title 출력

void user:: PrintData(){
   cout.width(10);     //10칸 지정
   cout << m_name;//이름
   cout.width(10);     //10칸 지정
   cout << m_allow;//용돈
   cout.width(10);     //10칸 지정
   cout << m_expence;//총지출액
   cout.width(10);     //10칸 지정
   cout << " "<<m_balance;//남은 돈
   cout << "\n";


}//일반멤버변수 값 출력

void user :: Print(){
   PrintTitle();
   PrintData();

   int i;
   
  
   for(i=0;i<m_day_num;i++){
      m_dday[i].PrintData();   
   }
}//멤버변수와 클래스 멤버변수 값 출력



void user:: Modify(){

   cout << "*("
       << m_name
       <<", " 
       << m_allow 
       <<")의 정보를 수정하세요.\n"; //안내문 출력.


      cin.ignore();
      cout << "이름: ";
      InputUtil::InputValue(m_name);
      cout << "용돈: ";
      InputUtil::InputValue(m_allow);


}//일반멤버변수 값 수정


void user:: Calc(){
   int i; //반복 변수 선언.

   for(i=0;i<m_day_num;i++)//i=0부터 i가 날짜 수 만큼 i에 1을 더해가며 반복.
      m_expence+=m_dday[i].m_jichul; //지출액을 더한다.

   m_balance=m_allow-m_expence; //잔액
   

}// 계산

user::user(){//디폴트 생성자
   m_name="";
   m_allow=0;
   m_day_num=0;
   m_dday=0;
   m_expence=0;
   m_balance=0;
}

user::user(string m_name,int m_allow,int m_day_num,day* m_dday,int m_expence,int m_balance){//인자있는 생성자
   this->m_name = m_name;
   this->m_allow = m_allow;
   this->m_day_num = m_day_num;
   this->m_dday = m_dday;
   this->m_expence = m_expence;
   this->m_balance = m_balance;
}

user::user(const user& u){//복사 생성자
   m_name=u.m_name;
   m_allow=u.m_allow;
   m_day_num=u.m_day_num;
   m_expence=u.m_expence;
   m_balance=u.m_balance;
   
   m_dday=new day[m_day_num];
   memcpy(m_dday,u.m_dday,sizeof(day)*m_day_num);
}



day* user:: daySearch(){
 
   cout << "\n검색 할 날짜 : ";  //안내문 출력.
   int num;         
   InputUtil::InputValue(num);

   int i;//반복문 변수 선언.
 
   for(i=0;i<m_day_num;i++){ //i=0부터 i=m_day_num 만큼 1을 더해가며 반복.
      if(num==(m_dday+i)->m_dday) //찾는 날짜가 있으면
         return m_dday+i;//그 이름의 주소를 리턴.
   }
   return NULL; //null값을 리턴.
}

void user:: Get(string name){
	m_name=name;
}



user::~user(){//소멸자
   delete[] m_dday;
   m_dday=NULL;
}