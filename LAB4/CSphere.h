#pragma once
#include "CBody.h"

class CSphere final:public CBody
{//ספונא (ראנ)
public:
	CSphere(double mradius, double mdensity);

	double GetRadius()const;
	double GetMass()const override;
	double GetVolume()const override;
	double GetDensity()const override;
private:
	void AppendProperties(ostream& strm) const override;
	double radiusSphere;
	double densitySphere;
};