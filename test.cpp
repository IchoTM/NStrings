#include <iostream>
#include "nstring.h"

//All this is just for test purposes and has no effct on the use of this class nor should it be used as an example
int main()
{
	nstring test;
	vector<nstring> divd;
	test = "280.039.459";
	divd = test.divideByDelim('.',true);
	cout << divd[0] << ' ' << divd[1] << ' ' << divd[2] << endl;
	test = "balls";
	!test;
	cout << test;

}