#include <iostream>
#include "expStr.h"

int main()
{
	expStr test;
	expStr save;
	test.append("this is_a test_of sheerUntilMarker");
	
	//test.sheer(save, 0, 5);

	/*cout << save << endl;
	cout << test << endl;*/

	test.sheerUntilMarker(save, '_', 8, false);
	
	cout << save << endl;
	cout << test << endl;
}