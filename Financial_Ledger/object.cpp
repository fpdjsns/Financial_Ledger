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



}//����Ʈ������


 object :: object (const object& obj){

	m_obname = obj.m_obname;
	m_price = obj.m_price;
	m_amount = obj.m_amount;
	m_sumprice = obj.m_sumprice;
	Calc();

 }



void object :: PrintTitle()const{

	cout<<"======================================================\n";
	cout<<"      ��ǰ��     �ܰ�     ����    �ݾ�   \n";
	cout<<"======================================================\n";

}//Ÿ��Ʋ
void object :: InputData(){
	cin.ignore();
	cout<<"\n������ �̸��� �Է��Ͻÿ� :";
	InputUtil::InputValue(m_obname);
	cout<<"������ �Է��Ͻÿ� : ";
	InputUtil::InputValue(m_amount);
	cout<<"���� �Է��Ͻÿ� : ";
	InputUtil::InputValue(m_price);
	Calc();

}//�Ϲݸ������ �� �Է�

void  object ::Calc(){

	m_sumprice = m_amount *m_price;

};//���

void object :: PrintData(){


	cout.width(10);      //10ĭ ����
	cout << m_obname; //�����̸� ���.
	cout.width(10);      //10ĭ ����
	cout << m_price;     //���ǰ������
	cout.width(10);      //10ĭ ����
	cout << m_amount;  //���� ���� ���.
	cout.width(10);      //10ĭ ����
	cout <<m_sumprice ;  //���� ���� ���.
	cout << "\n";

}//�������


void object :: Modify(){
	
	cin.ignore();
	cout<<"������ �̸��� �Է��Ͻÿ�";
	InputUtil::InputValue(m_obname);
	cout<<"������ �Է��Ͻÿ�";
	InputUtil::InputValue(m_amount);
	cout<<"���� �Է��Ͻÿ�";
	InputUtil::InputValue(m_price);
	Calc();



};//����


 object ::~object(){

 }