#include <iostream>
#include "nstring.h"

//All this is just for test purposes and has no effct on the use of this class nor should it be used as an example
int main()
{
	nstring test;
	nstring uwu;
	uwu = "teehee";
	vector<nstring> divd;
	cin >> test;
	divd = test.divideByDelim('.',true);
	cout << divd[0] << ' ' << divd[1] << ' ' << divd[2] << endl;
	test = "balls";
	test;
	test = test + uwu;
	!uwu;
	cout << test[3];
	if (test != uwu) { cout << "TRUE!" << endl;}
}