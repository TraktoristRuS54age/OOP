#include "stdafx.h"
#include "CParallelepiped.h"

CParallelepiped::CParallelepiped(double mwidth, double mheight, double mdepth, double mdensity)
	:CBody("Parallelepiped", mdensity)
	, widthParall(mwidth)
	, heightParall(mheight)
	, depthParall(mdepth)
	, densityParall(mdensity)
{
}

double CParallelepiped::GetWidth()const
{
	return widthParall;
}

double CParallelepiped::GetHeight()const
{
	return heightParall;
}

double CParallelepiped::GetDepth()const
{
	return depthParall;
}

double CParallelepiped::GetMass()const
{
	return GetVolume() * GetDensity();
}

double CParallelepiped::GetVolume()const
{
	return GetDepth() * GetWidth() * GetHeight();
}

double CParallelepiped::GetDensity()const
{
	return densityParall;
}

void CParallelepiped::AppendProperties(ostream& strm) const
{
	strm << "\theight = " << GetHeight() << '\n'
		<< "\twidth = " << GetWidth() << '\n'
		<< "\tdepth = " << GetDepth() << '\n';
}