#include "stdafx.h"
#include "CCompound.h"

CCompound::CCompound(vector<shared_ptr<CBody>> mchild)
	:CBody("Compound", GetDensity())
	, childs(mchild)
{
}

bool CCompound::AddChildBody(shared_ptr<CBody> child)
{
	childs.push_back(child);
	return true;
}

double CCompound::GetVolume() const
{
	double totalVolume = 0;
	for (const auto& child : childs)
	{
		totalVolume += child->GetVolume();
	}
	return totalVolume;
}

double CBody::GetDensity()const
{
	return density;
}

double CBody::GetMass() const
{
	return GetVolume() * GetDensity();
}

double CCompound::GetMass() const
{
	double totalMass = 0;
	for (const auto& part : childs)
	{
		totalMass += part->GetMass();
	}
	return totalMass;
}

double CCompound::GetDensity() const
{
	double totalMass = 0;
	for (const auto& part : childs)
	{
		totalMass += part->GetMass();
	}
	double totalVolume = 0;
	for (const auto& child : childs)
	{
		totalVolume += child->GetVolume();
	}
	return totalMass / totalVolume;
}

void CCompound::AppendProperties(ostream& strm) const
{
	return;
}