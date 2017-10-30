#ifndef _DAY_H
#define _DAY_H


#include<iostream>
#include <string>
#include <iomanip>
#include"object.h"

using namespace std;

class day: public printutil{

   protected :
      int m_dday;//당일날짜
      int m_obnum;//물건수
      object* m_object;//물건정보
      int m_jichul;//당일지출액

   public:
      //inline void Initialize(int dday=0,int obnum=0,object* oobject=0,int jichul=0); //초기화
      void InputData(); //멤버변수값 입력
      void PrintTitle()const; // 멤버변수  메뉴출력
      void PrintData();  // 멤버변수 값 출력
      void Modify();     // 날짜 수정
      void Calc();// 당일지출액 계산
	  object* objectSearch();//물건 검색


      day(); //디폴트 생성자
      day(int dday,int obnum,object* oobject,int jichul);//인자있는 생성자
      day(const day& d);//복사생성자
      ~day();//소멸자


      friend class user;

};//날짜클래스

#endif