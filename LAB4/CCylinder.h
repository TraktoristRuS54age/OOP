#pragma once
#include "CBody.h"

class CCylinder final:public CBody
{//цилиндр
public:
	CCylinder(double mradius, double mheight, double mdensity);

	double GetRadius()const;
	double GetHeight()const;
	double GetVolume()const override;
	double GetMass()const override;
	double GetDensity()const override;
private:
	void AppendProperties(ostream& strm) const override;
	double radiusCylinder;
	double heightCylinder;
	double densityCylinder;
};