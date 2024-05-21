#pragma once
#include "CBody.h"


class CBodyControl
{
public:
	CBodyControl(vector<shared_ptr<CBody>>& bodies, istream& inp, ostream& out);
	void ReadBodies();
	void WriteBodies();
	void WriteHaviestBody();
	void WriteLightestBodyInWater()const;
private:
	shared_ptr<CBody> ReadSimpleBody() const;
	vector<shared_ptr<CBody>> ReadCompoundBody() const;
	shared_ptr<CBody> FindHeaviestBody() const;
	shared_ptr<CBody> FindLightestInWaterBody() const;
	vector<shared_ptr<CBody>>& mbodies;
	istream& minp;
	ostream& mout;
};