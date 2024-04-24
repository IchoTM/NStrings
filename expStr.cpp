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
	while (itr < len--)
	{
		len = this->length();
		//worlds dumbest fucking conditaional ever
		if(scan[itr] == '#' || scan[itr] == '%' || scan[itr] == '&' || scan[itr] == '{' || scan[itr] == '}' || scan[itr] == '\\' || scan[itr] == '<' || scan[itr] == '>' || scan[itr] == '*' || scan[itr] == '?' || scan[itr] == '/' || scan[itr] == '$' || scan[itr] == '!' || scan[itr] == '\'' || scan[itr] == '\"' || scan[itr] == ':' || scan[itr] == '@' || scan[itr] == '+' || scan[itr] == '`' || scan[itr] == '|' || scan[itr] == '=')
		{
			this->erase(itr, 1);
		}
		else if(scan[itr] == ' ')
		{
			scan[itr] = '_';
		}
		itr++;
	}
	this->erase();
	this->append(scan);
}