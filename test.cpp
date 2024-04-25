#include <iostream>
#include "expStr.h"

//All this is just for test purposes and has no effct on the use of this class nor should it be used as an example
int main()
{
	expStr test;
	expStr save;
	test.append("This is a test of sheer");
	test.sheer(save, 0, 5);
	cout << save << endl;
	cout << test << endl;
	test.erase();
	test.append("this is_a test_of sheerUntilMarker");
	test.sheerUntilMarker(save, '_', 15, false);
	cout << save << endl;
	cout << test << endl;
	test.erase();
	test.baseLaw();
	test.append("this is @n example* of au#o format|ng");
	save.append("@@");
	save.baseLaw();
	save.rmvLaw('@');
	save.autoForm();
	test.autoForm();
	cout << test << save << endl;
	test.getLaws();
	save.getLaws();
}