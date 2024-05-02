#include "expStr.h"

void expStr::sheer(string& save, int startLoc, int sheerAmt)
{
	save = "";
	save.append(*this, startLoc, sheerAmt);
	this->erase(startLoc, sheerAmt);
}
void expStr::sheerUntilMarker(string& save, char marker, int startLoc, bool removeMarker)
{
	save = "";
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

	save.append(*this, startLoc, markDist);
	if (removeMarker) 
	{
		markDist += 1;
		this->erase(startLoc, markDist);
	}
	else
	{
		this->erase(startLoc, markDist);
	}
}
void expStr::autoForm()
{
	int len = this->length();
	int itr = 0;
	expStr scan;
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
bool expStr::isIllegal(char sus)
{
	for(char ill : expStr::illegalChars)
	{
		if(sus == ill)
		{
			return true;
		}
	}
	return false;
}
void expStr::addLaw(char outlaw)
{
	illegalChars.push_back(outlaw);
}
void expStr::baseLaw()
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
void expStr::rmvLaw(char legal)
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
void expStr::getLaws() const
{
	cout << "Laws: ";
	for(char law : illegalChars)
	{
		cout << law << ' ';
	}
	cout << endl;
}
vector<expStr> expStr::divideByDelim(char delim, bool clear)
{
	int itr = 0;
	expStr scan = *this;
	vector<expStr> divided;
	expStr addition;
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
vector<expStr> expStr::divideByLength(int divisor)
{
	//Work in progress
	int length = this->length();
	int segLen;
	int itr = 0;
	int loc;
	expStr scan;
	expStr ape;
	vector<expStr> res;

	if(length % divisor == 0)
	{
		segLen = length / divisor;

		while (itr < length)
		{
			loc = 0;
			ape.erase();
			while (loc < segLen)
			{
				loc++;
				//ape += scan[loc];
				cout << loc << ' ' << itr << ' ' << length << endl;
			}
			itr += divisor;
			res.push_back(ape);
		}
	}

	return res;
}
expStr& expStr::operator=(const char str[])
{
	this->erase();
	this->append(str);
	return *this;
}
expStr& expStr::operator+=(char add)
{
	string ad;
	ad = add;
	this->append(ad);
	return *this;
}