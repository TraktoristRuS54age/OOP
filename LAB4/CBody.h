#pragma once
#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#define _USE_MATH_DEFINES

class CBody
{//основное тело
public:
	CBody(const string& type, double mdensity);

	virtual double GetDensity()const = 0;//плотность
	virtual double GetVolume()const = 0;//объём
	virtual double GetMass()const = 0;//масса
	string ToString()const;//информация 

	virtual ~CBody() = default;
private:
	virtual void AppendProperties(ostream& strm) const = 0;
	double density;
	string str;
};