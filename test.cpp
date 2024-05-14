#include <iostream>
#include "nstring.h"

//All this is just for test purposes and has no effct on the use of this class nor should it be used as an example
int main()
{
	nstring test;
	nstring uwu;
	uwu = "teehee";
	test = "balls";
	test += uwu;
	cout << test;
	if (test != uwu) { cout << "TRUE!" << endl;}
}