#include <iostream>
#include <string>
#include <iomanip>
#include "user.h"
#include "InputUtil.h"


;using namespace std;


void user:: InputData(){
   //cin.ignore();
  // cout << "����ڸ�: ";
  // InputUtil:: InputValue(m_name);
	cout<<"==========================================================================\n\n";
   cout << "         �뵷 : ";
   InputUtil::InputValue(m_allow);
   cout << "         �Һ��� ��¥ �� : ";
   InputUtil::InputValue(m_day_num);
   cout<<"\n===========================================================================\n\n";
   cout << "\n";

   m_dday=new day[m_day_num]; //�����Ҵ�

   int i;
   for(i=0;i<m_day_num;i++)
      m_dday[i].InputData();

    Calc();//���
}//�Ϲݸ������ �� �Է�


void user:: PrintTitle()const{
   cout << "================================================\n";
   cout << "     �̸�       �뵷    �������      ���� ��\n";        //�ȳ��� ���.
   cout << "================================================\n";
}//�Ϲݸ������ title ���

void user:: PrintData(){
   cout.width(10);     //10ĭ ����
   cout << m_name;//�̸�
   cout.width(10);     //10ĭ ����
   cout << m_allow;//�뵷
   cout.width(10);     //10ĭ ����
   cout << m_expence;//�������
   cout.width(10);     //10ĭ ����
   cout << " "<<m_balance;//���� ��
   cout << "\n";


}//�Ϲݸ������ �� ���

void user :: Print(){
   PrintTitle();
   PrintData();

   int i;
   
  
   for(i=0;i<m_day_num;i++){
      m_dday[i].PrintData();   
   }
}//��������� Ŭ���� ������� �� ���



void user:: Modify(){

   cout << "*("
       << m_name
       <<", " 
       << m_allow 
       <<")�� ������ �����ϼ���.\n"; //�ȳ��� ���.


      cin.ignore();
      cout << "�̸�: ";
      InputUtil::InputValue(m_name);
      cout << "�뵷: ";
      InputUtil::InputValue(m_allow);


}//�Ϲݸ������ �� ����


void user:: Calc(){
   int i; //�ݺ� ���� ����.

   for(i=0;i<m_day_num;i++)//i=0���� i�� ��¥ �� ��ŭ i�� 1�� ���ذ��� �ݺ�.
      m_expence+=m_dday[i].m_jichul; //������� ���Ѵ�.

   m_balance=m_allow-m_expence; //�ܾ�
   

}// ���

user::user(){//����Ʈ ������
   m_name="";
   m_allow=0;
   m_day_num=0;
   m_dday=0;
   m_expence=0;
   m_balance=0;
}

user::user(string m_name,int m_allow,int m_day_num,day* m_dday,int m_expence,int m_balance){//�����ִ� ������
   this->m_name = m_name;
   this->m_allow = m_allow;
   this->m_day_num = m_day_num;
   this->m_dday = m_dday;
   this->m_expence = m_expence;
   this->m_balance = m_balance;
}

user::user(const user& u){//���� ������
   m_name=u.m_name;
   m_allow=u.m_allow;
   m_day_num=u.m_day_num;
   m_expence=u.m_expence;
   m_balance=u.m_balance;
   
   m_dday=new day[m_day_num];
   memcpy(m_dday,u.m_dday,sizeof(day)*m_day_num);
}



day* user:: daySearch(){
 
   cout << "\n�˻� �� ��¥ : ";  //�ȳ��� ���.
   int num;         
   InputUtil::InputValue(num);

   int i;//�ݺ��� ���� ����.
 
   for(i=0;i<m_day_num;i++){ //i=0���� i=m_day_num ��ŭ 1�� ���ذ��� �ݺ�.
      if(num==(m_dday+i)->m_dday) //ã�� ��¥�� ������
         return m_dday+i;//�� �̸��� �ּҸ� ����.
   }
   return NULL; //null���� ����.
}

void user:: Get(string name){
	m_name=name;
}



user::~user(){//�Ҹ���
   delete[] m_dday;
   m_dday=NULL;
}