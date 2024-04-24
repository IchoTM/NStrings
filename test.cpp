#include <iostream>
#include "expStr.h"

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

	test.sheerUntilMarker(save, '_', 8, false);
	
	cout << save << endl;
	cout << test << endl;

	test.erase();
	test.append("this is an example of auto formating");

	test.autoForm();
	cout << test << endl;
}