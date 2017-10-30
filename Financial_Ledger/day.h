#ifndef _DAY_H
#define _DAY_H


#include<iostream>
#include <string>
#include <iomanip>
#include"object.h"

using namespace std;

class day: public printutil{

   protected :
      int m_dday;//���ϳ�¥
      int m_obnum;//���Ǽ�
      object* m_object;//��������
      int m_jichul;//���������

   public:
      //inline void Initialize(int dday=0,int obnum=0,object* oobject=0,int jichul=0); //�ʱ�ȭ
      void InputData(); //��������� �Է�
      void PrintTitle()const; // �������  �޴����
      void PrintData();  // ������� �� ���
      void Modify();     // ��¥ ����
      void Calc();// ��������� ���
	  object* objectSearch();//���� �˻�


      day(); //����Ʈ ������
      day(int dday,int obnum,object* oobject,int jichul);//�����ִ� ������
      day(const day& d);//���������
      ~day();//�Ҹ���


      friend class user;

};//��¥Ŭ����

#endif