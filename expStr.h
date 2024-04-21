#include <string>
#include <iostream>
using namespace std;
class expStr : public string
{
	public:
		void sheer(string&, string&, int, int);
		void sheerUntilMarker(string&, string&, char, int, bool);
};
