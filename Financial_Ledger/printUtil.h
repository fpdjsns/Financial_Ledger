
#include <iostream>
#include <string>
#include <iomanip>

;using namespace std;


class printutil{

public:

	virtual void PrintData()=0;
	virtual void PrintTitle() const=0;
	virtual void Modify()=0;
	virtual ~printutil(){};

};

