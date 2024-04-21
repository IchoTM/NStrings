#include <iostream>
#include "expStr.h"

int main()
{
	expStr test;
	expStr save;
	test.append("this is_a test_of sheerUntilMarker");
	test.sheerUntilMarker(test, save, '_', 0, true);

	cout << save << endl;
	cout << test << endl;

	test.sheerUntilMarker(test, save, '_', 8, true);

	cout << save << endl;
	cout << test << endl;
}