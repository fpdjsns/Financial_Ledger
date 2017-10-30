#include<iostream>
#include <string>
#include <iomanip>
#include "InputUtil.h"
#include "day.h"

using namespace std;


void day::InputData(){

   cin.ignore();
   
   cout<<"��¥�� �Է��Ͻÿ� : ";
   InputUtil::InputValue(m_dday);
   cout<<"���û� ���Ǽ��� �Է��Ͻÿ� : ";
   InputUtil::InputValue(m_obnum);
   cout<<"\n===========================================================\n";
   this->m_object= new object[m_obnum];
    int i;
     for(i=0;i<m_obnum;i++)
            m_object[i].InputData();
	 cout<<"\n===========================================================\n";
	 cout<<"===========================================================\n";

   Calc();


}//��������� �Է�

void day:: Calc(){
   
   int i;
    m_jichul=0;

     for(i=0;i<m_obnum;i++)
       m_jichul+=m_object[i].m_sumprice;



}// ��������� ���


void day:: Modify(){
    cout << "*("
       << m_dday
       <<", " 
       << m_obnum
       <<")�� ������ �����ϼ���.\n"; //�ȳ��� ���.
    
   cin.ignore();
   cout<<"\n         ��¥�� �Է��Ͻÿ� :";
   InputUtil::InputValue(m_dday);
   cout<<"\n";
   


};//����


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
		<<"      ��¥                �����       \n"
		<<"=======================================\n";



}// �������  �޴����



void day :: PrintData(){

	PrintTitle();
	cout<<"       "<<m_dday<<"                     "<<m_jichul<<"\n";

	int i;

	cout<<"\n\n��ü���� ������ Ȯ���Ͻðڽ��ϱ�?<YES:1,NO:2>";
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


}// ������� �� ���


object* day:: objectSearch(){
 
   cout << "\n�˻� �� ���� �̸� : ";  //�ȳ��� ���.
   string name;         
   InputUtil::InputValue(name);
   
   int i;//�ݺ��� ���� ����.
 
   for(i=0;i<m_obnum;i++){ //i=0���� i=m_day_num ��ŭ 1�� ���ذ��� �ݺ�.
      if(name.compare((m_object+i)->m_obname)==0) //ã�� ��¥�� ������
         return m_object+i;//�� �̸��� �ּҸ� ����.
   }
   return NULL; //null���� ����.
}

day ::~day(){

	delete[] m_object;
   m_object=NULL;

}//�Ҹ���
