#include "stdafx.h"
#include "CCylinder.h"

CCylinder::CCylinder(double mradius, double mheight, double mdensity)
	:CBody("Cylinder", mdensity)
	, radiusCylinder(mradius)
	, heightCylinder(mheight)
	, densityCylinder(mdensity)
{
}

double CCylinder::GetRadius() const
{
	return radiusCylinder;
}

double CCylinder::GetHeight() const
{
	return heightCylinder;
}

double CCylinder::GetDensity() const
{
	return densityCylinder;
}

double CCylinder::GetVolume() const
{
	return M_PI * pow(radiusCylinder, 2) * heightCylinder;
}

double CCylinder::GetMass() const
{
	return GetVolume() * GetDensity();
}

void CCylinder::AppendProperties(ostream& strm) const
{
	strm << "\tbase radius = " << GetRadius() << '\n'
		<< "\theight = " << GetHeight() << '\n';
}