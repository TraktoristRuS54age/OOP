#pragma once
#include "CBody.h"

class CCompound :public CBody
{//соединение
public:
	CCompound(vector<shared_ptr<CBody>>);
	
	bool AddChildBody(shared_ptr<CBody> child);
	double GetDensity()const override;
	double GetMass()const override;
	double GetVolume()const override;
private:
	vector<shared_ptr<CBody>> childs;
	void AppendProperties(ostream& strm) const override;
};