#include<iostream>
#include <string>
#include <iomanip>
#include "InputUtil.h"
#include "day.h"

using namespace std;


void day::InputData(){

   cin.ignore();
   
   cout<<"날짜를 입력하시오 : ";
   InputUtil::InputValue(m_dday);
   cout<<"오늘산 물건수를 입력하시오 : ";
   InputUtil::InputValue(m_obnum);
   cout<<"\n===========================================================\n";
   this->m_object= new object[m_obnum];
    int i;
     for(i=0;i<m_obnum;i++)
            m_object[i].InputData();
	 cout<<"\n===========================================================\n";
	 cout<<"===========================================================\n";

   Calc();


}//멤버변수값 입력

void day:: Calc(){
   
   int i;
    m_jichul=0;

     for(i=0;i<m_obnum;i++)
       m_jichul+=m_object[i].m_sumprice;



}// 당일지출액 계산


void day:: Modify(){
    cout << "*("
       << m_dday
       <<", " 
       << m_obnum
       <<")의 정보를 수정하세요.\n"; //안내문 출력.
    
   cin.ignore();
   cout<<"\n         날짜를 입력하시오 :";
   InputUtil::InputValue(m_dday);
   cout<<"\n";
   


};//수정


day ::day(){
   m_dday=0;
   m_obnum=0;
   m_jichul=0;
   //m_Sub=new Subject [m_SubNum];
   m_object= new object[m_obnum];
   m_object=0;
}

day ::day(int dday,int obnum,object* oobject,int jichul){
   this->m_dday=dday;
   this->m_obnum=obnum;
   this->m_jichul=jichul;
   //m_Sub=new Subject [m_SubNum];
   this->m_object= new object [m_obnum];
   this->m_object=oobject;
}


void day ::PrintTitle()const{


	cout<<"=======================================\n"
		<<"      날짜                지출액       \n"
		<<"=======================================\n";



}// 멤버변수  메뉴출력



void day :: PrintData(){

	PrintTitle();
	cout<<"       "<<m_dday<<"                     "<<m_jichul<<"\n";

	int i;

	cout<<"\n\n구체적인 내역을 확인하시겠습니까?<YES:1,NO:2>";
	cin>>i;

	if(i==1){

		m_object[0].PrintTitle();
		cout<<"\n";

	for(int j=0;j<m_obnum;j++)
	{
		m_object[j].PrintData();
		cout<<"\n";
	}

	}


}// 멤버변수 값 출력


object* day:: objectSearch(){
 
   cout << "\n검색 할 물건 이름 : ";  //안내문 출력.
   string name;         
   InputUtil::InputValue(name);
   
   int i;//반복문 변수 선언.
 
   for(i=0;i<m_obnum;i++){ //i=0부터 i=m_day_num 만큼 1을 더해가며 반복.
      if(name.compare((m_object+i)->m_obname)==0) //찾는 날짜가 있으면
         return m_object+i;//그 이름의 주소를 리턴.
   }
   return NULL; //null값을 리턴.
}

day ::~day(){

	delete[] m_object;
   m_object=NULL;

}//소멸자
