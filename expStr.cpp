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