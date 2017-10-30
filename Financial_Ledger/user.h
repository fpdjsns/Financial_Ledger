#ifndef _USER_H
#define _USER_H

#include<iostream>
#include <string>
#include <iomanip>
#include"day.h"

using namespace std;



class user:public printutil{

   protected :
      string m_name;//�̸�
      int m_allow;//�뵷
      int m_day_num;//��¥�Է¼�
      day* m_dday;//��¥����
      int m_expence;//�������
      int m_balance;//�ܾ�

   public:
      //inline void Initialize(string name="",int allow=0,int day_num=0,day* dday=0,int expence=0,int balance=0); //�ʱ�ȭ 
      void InputData(); //��������� �Է�
     //  void Remove();   //�޸� ����
       void PrintTitle()const;  //������� title ���
       void PrintData();  //������� �� ���
       void Print();   //��������� Ŭ���� ������� �� ���
       void Modify();   //������� �� ����
       void Calc();  //�� ����� ���
	   void Get(string name); //����� �̸�
	   day* daySearch();//��¥�˻�

      user();//����Ʈ ������
      ~user();//�Ҹ���
      user(string m_name,int m_allow,int m_day_num,day* m_dday,int m_expence,int m_balance);//�����ִ� ������
      user(const user& u);//���� ������
       


};//����� Ŭ����

#endif