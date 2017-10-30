#ifndef _USER_H
#define _USER_H

#include<iostream>
#include <string>
#include <iomanip>
#include"day.h"

using namespace std;



class user:public printutil{

   protected :
      string m_name;//이름
      int m_allow;//용돈
      int m_day_num;//날짜입력수
      day* m_dday;//날짜정보
      int m_expence;//총지출액
      int m_balance;//잔액

   public:
      //inline void Initialize(string name="",int allow=0,int day_num=0,day* dday=0,int expence=0,int balance=0); //초기화 
      void InputData(); //멤버변수값 입력
     //  void Remove();   //메모리 해제
       void PrintTitle()const;  //멤버변수 title 출력
       void PrintData();  //멤버변수 값 출력
       void Print();   //멤버변수와 클래스 멤버변수 값 출력
       void Modify();   //멤버변수 값 수정
       void Calc();  //총 지출액 계산
	   void Get(string name); //사용자 이름
	   day* daySearch();//날짜검색

      user();//디폴트 생성자
      ~user();//소멸자
      user(string m_name,int m_allow,int m_day_num,day* m_dday,int m_expence,int m_balance);//인자있는 생성자
      user(const user& u);//복사 생성자
       


};//사용자 클래스

#endif