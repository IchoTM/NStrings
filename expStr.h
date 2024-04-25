#include <string>
#include <iostream>
#include <vector>
using namespace std;
class expStr : public string
{
	private:
		vector<char> illegalChars;
		//char illegalChars[21] = {'#','%','&','{','}','\\','<','>','*','?','/','$','!','\'','\"',':','@','+','`','|','='};
		bool isIllegal(char);
	public:
		void sheer(string&, int, int);
		void sheerUntilMarker(string&, char, int, bool);
		void autoForm();
		void addLaw(char);
		void baseLaw();
		void rmvLaw(char);
		void getLaws() const;
};
