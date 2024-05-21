#pragma once
#include "CBody.h"

class CCone final:public CBody
{//конус
public:
	CCone(double mradius, double mheight, double mdensity);

	double GetRadius()const;
	double GetHeight()const;
	double GetVolume()const override;
	double GetMass()const override;
	double GetDensity()const override;
private:
	void AppendProperties(ostream& strm) const override;
	double radiusCone;
	double heightCone;
	double densityCone;
};