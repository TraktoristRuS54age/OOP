#pragma once
#include "CBody.h"

class CParallelepiped final:public CBody
{//параллелепипед
public:
	CParallelepiped(double mwidth, double mheight, double mdepth, double mdensity);

	double GetWidth()const;
	double GetHeight()const;
	double GetDepth()const;
	double GetMass()const override;
	double GetVolume()const override;
	double GetDensity()const override;
private:
	double widthParall;
	double heightParall;
	double depthParall;
	double densityParall;
	void AppendProperties(ostream& strm) const override;
};