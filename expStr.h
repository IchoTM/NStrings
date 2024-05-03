#include <string>
#include <iostream>
#include <vector>
using namespace std;
class expStr : public string
{
	private:
		vector<char> illegalChars;
		bool isIllegal(char);
	public:
		void sheer(string&, int, int);
		void sheerUntilMarker(string&, char, int, bool);
		void autoForm();
		void addLaw(char);
		void baseLaw();
		void rmvLaw(char);
		void getLaws() const;
		vector<expStr> divideByDelim(char,bool);
		expStr& operator=(const char[]);
		expStr& operator+=(char);
};
