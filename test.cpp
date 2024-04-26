#include <iostream>
#include "expStr.h"

//All this is just for test purposes and has no effct on the use of this class nor should it be used as an example
int main()
{
	expStr test;
	expStr save;
	vector<expStr> divd;
	test.append("190.029.63");
	divd = test.divideByDelim('.');
	cout << divd[0] << ' ' << divd[1] << ' ' << divd[2];
}