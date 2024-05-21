#include "stdafx.h"
#include "CSphere.h"

CSphere::CSphere(double mradius, double mdensity) 
	:CBody("Sphere", mdensity)
	,radiusSphere(mradius)
	,densitySphere(mdensity)
{
}

double CSphere::GetRadius()const
{
	return radiusSphere;
}

double CSphere::GetVolume()const 
{
	return (pow(radiusSphere, 3) *M_PI) * 4/3;
}

double CSphere::GetMass()const
{
	return GetVolume() * GetDensity();
}

double CSphere::GetDensity()const
{
	return densitySphere;
}

void CSphere::AppendProperties(ostream& strm) const
{
	strm << "\tradius = " << GetRadius() << '\n';
}