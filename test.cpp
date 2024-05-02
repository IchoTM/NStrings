#include <iostream>
#include "expStr.h"

//All this is just for test purposes and has no effct on the use of this class nor should it be used as an example
int main()
{
	expStr test;
	expStr save;
	vector<expStr> divd;
	test = "190029630";
	test = "280039459";
	divd = test.divideByLength(3);
	cout << divd[0] << ' ' << divd[1] << ' ' << divd[2] << endl;
	cout << test;
}