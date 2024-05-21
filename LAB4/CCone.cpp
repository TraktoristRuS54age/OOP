#include "stdafx.h"
#include "CCone.h"

CCone::CCone(double mradius, double mheight, double mdensity)
	:CBody("Cone", mdensity)
	, radiusCone(mradius)
	, heightCone(mheight)
	, densityCone(mdensity)
{
}

double CCone::GetRadius()const
{
	return radiusCone;
}

double CCone::GetHeight()const
{
	return heightCone;
}

double CCone::GetVolume()const
{
	return (1.0/3.0) * M_PI * pow(radiusCone, 2) * heightCone;
}

double CCone::GetMass()const
{
	return GetVolume() * GetDensity();
}

double CCone::GetDensity()const
{
	return densityCone;
}

void CCone::AppendProperties(ostream& strm)const
{
	strm << "\tbase radius = " << GetRadius() << '\n'
		<< "\theight = " << GetHeight() << '\n';
}