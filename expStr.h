#include <string>
#include <iostream>
using namespace std;
class expStr : public string
{
	private:
		char illegalChars[21] = {'#','%','&','{','}','\\','<','>','*','?','/','$','!','\'','\"',':','@','+','`','|','='};
		bool isIllegal(char);
	public:
		void sheer(string&, int, int);
		void sheerUntilMarker(string&, char, int, bool);
		void autoForm();
};
