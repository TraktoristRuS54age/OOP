#pragma once
#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#define _USE_MATH_DEFINES

class CBody
{//�������� ����
public:
	CBody(const string& type, double mdensity);

	virtual double GetDensity()const = 0;//���������
	virtual double GetVolume()const = 0;//�����
	virtual double GetMass()const = 0;//�����
	string ToString()const;//���������� 

	virtual ~CBody() = default;
private:
	virtual void AppendProperties(ostream& strm) const = 0;
	double density;
	string str;
};