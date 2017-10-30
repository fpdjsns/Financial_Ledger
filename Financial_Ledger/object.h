#ifndef _OBJECT_H
#define _OBJECT_H

#include<iostream>
#include <string>
#include <iomanip>
#include"printUtil.h"

;using namespace std;


class object: public printutil {

	protected :
		string m_obname;//물건이름
		int m_price;//가격
		int m_amount;//물건수량
		int m_sumprice;//총가격

	public :
		object();
		~object();
		object(string obname,int price,int amount,int sumprice);
		object(const object& obj);
		void PrintTitle()const;//타이틀
		void PrintData();//정보출력
		void InputData();  //일반멤버변수 값 입력
		void Modify();//수정
		void Calc();//계산

		friend class day;
};//물건클래스
#endif