#include "nstring.h"

nstring nstring::sheer(int startLoc, int sheerAmt)
{
	nstring ret;
	ret.append(*this, startLoc, sheerAmt);
	this->erase(startLoc, sheerAmt);
	return ret;
}
nstring nstring::sheerUntilDelim(char marker, int startLoc, bool removeMarker)
{
	nstring ret;
	int markLocat = startLoc;
	int markDist = 0;
	string scan;
	scan = *this;

	while (scan[markLocat] != marker)
	{
		markDist++;
		markLocat++;
		if(markDist++ > scan.length())
		{
			cout << "index_out_of_bouds" << endl;
			break;
		}
	}

	ret.append(*this, startLoc, markDist);
	if (removeMarker) 
	{
		markDist += 1;
		this->erase(startLoc, markDist);
	}
	else
	{
		this->erase(startLoc, markDist);
	}
	
	return ret;
}
void nstring::autoForm()
{
	int len = this->length();
	int itr = 0;
	string scan;
	scan = *this;
	bool check;
	while (itr < len--)
	{
		check = isIllegal(scan[itr]);
		if(check == true)
		{
			scan.erase(itr,1);
			itr--;
		}
		else if(scan[itr] == ' ')
		{
			scan[itr] = '_';
		}
		itr++;
		len = scan.length();
	}
	this->erase();
	this->append(scan);
}
bool nstring::isIllegal(char sus)
{
	for(char ill : nstring::illegalChars)
	{
		if(sus == ill)
		{
			return true;
		}
	}
	return false;
}
void nstring::addLaw(char outlaw)
{
	illegalChars.push_back(outlaw);
}
void nstring::baseLaw()
{
	illegalChars.push_back('#');
	illegalChars.push_back('%');
	illegalChars.push_back('&');
	illegalChars.push_back('{');
	illegalChars.push_back('}');
	illegalChars.push_back('\\');
	illegalChars.push_back('<');
	illegalChars.push_back('>');
	illegalChars.push_back('*');
	illegalChars.push_back('?');
	illegalChars.push_back('/');
	illegalChars.push_back('$');
	illegalChars.push_back('!');
	illegalChars.push_back('\'');
	illegalChars.push_back('\"');
	illegalChars.push_back(':');
	illegalChars.push_back('@');
	illegalChars.push_back('+');
	illegalChars.push_back('`');
	illegalChars.push_back('|');
	illegalChars.push_back('=');
}
void nstring::rmvLaw(char legal)
{
	int pos = 0;
	for(char illegal : illegalChars)
	{
		pos++;
		if(illegal == legal)
		{
			pos--;
			illegalChars.erase(illegalChars.begin() + pos);
		}
	}
}
void nstring::getLaws() const
{
	cout << "Laws: ";
	for(char law : illegalChars)
	{
		cout << law << ' ';
	}
	cout << endl;
}
vector<nstring> nstring::divideByDelim(char delim, bool clear)
{
	int itr = 0;
	string scan = *this;
	vector<nstring> divided;
	nstring addition;
	int max = scan.length();

	while (itr <= max)
	{
		if (scan[itr] != delim && itr != max)
		{
			addition.append(string(1, scan[itr]));
		}
		else if (scan[itr] == delim || itr == max)
		{
			divided.push_back(addition);
			addition.erase();
		}
		itr++;
	}
	if (clear == true)
		this->erase();
	return divided;
}
nstring& nstring::operator=(const char str[])
{
	this->erase();
	this->append(str);
	return *this;
}
nstring& nstring::operator=(nstring str)
{
	this->erase();
	this->append(str);
	return *this;
}
nstring& nstring::operator+=(char add)
{
	string ad;
	ad = add;
	this->append(ad);
	return *this;
}
nstring& nstring::operator+=(nstring add)
{
	this->append(add);
	return *this;
}
nstring& nstring::operator+(nstring add)
{
	nstring ret;
	ret.append(*this);
	ret.append(add);
	return ret;
}
char nstring::operator[](int index)
{
	string base = *this;
	return base[index];
}
bool nstring::operator==(nstring test)
{
	string base = *this;
	string comp = test;

	if(base==comp)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool nstring::operator!=(nstring test)
{
	string base = *this;
	string comp = test;

	if (base != comp)
	{
		return true;
	}
	else
	{
		return false;
	}
}