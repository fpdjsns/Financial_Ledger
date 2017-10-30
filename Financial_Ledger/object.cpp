#include<iostream>
#include <string>
#include <iomanip>
#include "object.h"
#include "InputUtil.h"

;using namespace std;


 object :: object (string obname,int price,int  amount,int sumprice){

	m_obname = obname;
	m_price = price;
	m_amount = amount;
	m_sumprice = sumprice;
	Calc();

}


 
object :: object(){
 
 	m_obname = "";
	m_price = 0;
	m_amount = 0;
	m_sumprice = 0;
	Calc();



}//디폴트생성자


 object :: object (const object& obj){

	m_obname = obj.m_obname;
	m_price = obj.m_price;
	m_amount = obj.m_amount;
	m_sumprice = obj.m_sumprice;
	Calc();

 }



void object :: PrintTitle()const{

	cout<<"======================================================\n";
	cout<<"      상품명     단가     수량    금액   \n";
	cout<<"======================================================\n";

}//타이틀
void object :: InputData(){
	cin.ignore();
	cout<<"\n물건의 이름을 입력하시오 :";
	InputUtil::InputValue(m_obname);
	cout<<"개수를 입력하시오 : ";
	InputUtil::InputValue(m_amount);
	cout<<"가격 입력하시오 : ";
	InputUtil::InputValue(m_price);
	Calc();

}//일반멤버변수 값 입력

void  object ::Calc(){

	m_sumprice = m_amount *m_price;

};//계산

void object :: PrintData(){


	cout.width(10);      //10칸 지정
	cout << m_obname; //물건이름 출력.
	cout.width(10);      //10칸 지정
	cout << m_price;     //물건가격출력
	cout.width(10);      //10칸 지정
	cout << m_amount;  //물건 수량 출력.
	cout.width(10);      //10칸 지정
	cout <<m_sumprice ;  //물건 가격 출력.
	cout << "\n";

}//정보출력


void object :: Modify(){
	
	cin.ignore();
	cout<<"물건의 이름을 입력하시오";
	InputUtil::InputValue(m_obname);
	cout<<"개수를 입력하시오";
	InputUtil::InputValue(m_amount);
	cout<<"가격 입력하시오";
	InputUtil::InputValue(m_price);
	Calc();



};//수정


 object ::~object(){

 }