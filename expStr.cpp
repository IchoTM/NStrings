#include "expStr.h"

void expStr::sheer(string& target, string& save, int startLoc, int sheerAmt)
{
	save = "";
	save.append(target, startLoc, sheerAmt);
	target.erase(startLoc, sheerAmt);
}
void expStr::sheerUntilMarker(string& target, string& save, char marker, int startLoc, bool removeMarker)
{
	save = "";
	int markLocat = startLoc;
	int markDist = 0;

	while (target[markLocat] != marker)
	{
		markDist++;
		markLocat++;
	}

	save.append(target, startLoc, markDist);
	if (removeMarker) 
	{
		markDist += 1;
		target.erase(startLoc, markDist);
	}
	else
	{
		target.erase(startLoc, markDist);
	}
}