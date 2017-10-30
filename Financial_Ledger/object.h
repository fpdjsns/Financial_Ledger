#ifndef _OBJECT_H
#define _OBJECT_H

#include<iostream>
#include <string>
#include <iomanip>
#include"printUtil.h"

;using namespace std;


class object: public printutil {

	protected :
		string m_obname;//�����̸�
		int m_price;//����
		int m_amount;//���Ǽ���
		int m_sumprice;//�Ѱ���

	public :
		object();
		~object();
		object(string obname,int price,int amount,int sumprice);
		object(const object& obj);
		void PrintTitle()const;//Ÿ��Ʋ
		void PrintData();//�������
		void InputData();  //�Ϲݸ������ �� �Է�
		void Modify();//����
		void Calc();//���

		friend class day;
};//����Ŭ����
#endif