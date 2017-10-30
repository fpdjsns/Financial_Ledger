
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class InputUtil{
public:
   static void InputValue(int &i){
      cin>>i; 
   }
   static void InputValue(string &str){
      getline(cin,str);
   }
};