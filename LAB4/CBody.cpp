#include "stdafx.h"
#include "CBody.h"

CBody::CBody(const string& type, double mdensity)
	:density(mdensity)
	, str(type)
{
}

string CBody::ToString()const
{
	ostringstream strm;
	strm << str << ":" << '\n' << setprecision(10)
		<< "\tdensity = " << GetDensity() << '\n'
		<< "\tvolume = " << GetVolume() << '\n'
		<< "\tmass = " << GetMass() << '\n';
	AppendProperties(strm);
	return strm.str();
}