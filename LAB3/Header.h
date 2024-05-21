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

	bool TurnOnEngine();//включить двигатель
	bool TurnOffEngine();//выключить двигатель
	bool SetGear(short gear);//выбрать передачу для авто
	bool SetSpeed(short speed);//задать скорость
private:
	bool engineCondition{false};//состояние двигателя
	short direction{0};//направление движения
	short speed{0};//текущая скорость авто
	short transmission{0};//передача
};

void Info(Car& jeep);