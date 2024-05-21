#pragma once
#include <iostream>
#include <string>
#include <map>

class Car
{
public:
	bool IsTurnedOn()const { return engineCondition; }
	short GetDirection()const { return direction; }
	short GetSpeed()const { return speed; }
	short GetGear()const { return transmission; }

	bool TurnOnEngine();//�������� ���������
	bool TurnOffEngine();//��������� ���������
	bool SetGear(short gear);//������� �������� ��� ����
	bool SetSpeed(short speed);//������ ��������
private:
	bool engineCondition{false};//��������� ���������
	short direction{0};//����������� ��������
	short speed{0};//������� �������� ����
	short transmission{0};//��������
};

void Info(Car& jeep);