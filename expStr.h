#include <string>
#include <iostream>
using namespace std;
class expStr : public string
{
	public:
		void sheer(string&, int, int);
		void sheerUntilMarker(string&, char, int, bool);
		void autoForm();
};
