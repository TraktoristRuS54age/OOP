#include "Header.h"
const std::string TRANS = "Transmission is not equal 0";
const std::string SPEED = "Speed is not equal 0";
const std::string MINSPEED = "The speed is too low for this transmission";
const std::string MAXSPEED = "The speed is high for this transmission";
const std::string NSPEED = "Speed cannot be changed because gear = 0";
const std::string ENGINEOFF = "Engine off";
const std::string GEARZERO = "Engine off and gear is not equal 0";
const std::string MINGEAR = "Speed is low, gear cannot be changed";
const std::string MAXGEAR = "The speed is high, the gear cannot be changed";

bool Car::TurnOnEngine() {
	if (!engineCondition) {
		engineCondition = true;
		return true;
	}
	else {
		return true;
	}
}

bool Car::TurnOffEngine() {
	if ((engineCondition) && (transmission == 0) && (speed == 0)) {
		engineCondition = false;
		return true;
	}
	else {
		if (transmission != 0) std::cout << TRANS << std::endl;
		if (speed != 0) std::cout << SPEED << std::endl;
		if (!engineCondition) std::cout << ENGINEOFF << std::endl;
		return false;
	}
}

bool Car::SetGear(short gear) {
	if (!engineCondition) {
		if (gear == 0) {
			transmission = gear;
			speed = 0;
			direction = 0;
			return true;
		}
		std::cout << GEARZERO << std::endl;
		return false;
	}

	std::map<short, std::pair<int, int>> gear_map = {
		{5, {50, 150}},
		{4, {40, 90}},
		{3, {30, 60}},
		{2, {20, 50}},
		{1, {0, 30}},
		{-1, {0, 0}}
	};

	auto it = gear_map.find(gear);
	if (it != gear_map.end() && speed >= it->second.first && speed <= it->second.second && ((direction == 1 || direction == 0) || (direction == 1 && gear == 1) || (direction == -1 && gear == -1))) {
		transmission = gear;
		return true;
	}

	if (gear == 0) {
		transmission = gear;
		return true;
	}
	else {
		if (speed <= it->second.first) {
			std::cout << MINGEAR << std::endl;
		}
		if (speed >= it->second.second) {
			std::cout << MAXGEAR << std::endl;
		}
		return false;
	}
	//if (!engineCondition) {
	//	if (gear == 0) {
	//		transmission = gear;
	//		speed = 0;
	//		direction = 0;
	//		return true;
	//	}
	//	if (gear != 0) {
	//		return false;
	//	}
	//}
	//else {
	//	if ((gear == 5) && (speed >= 50)) {
	//		transmission = gear;
	//		return true;
	//	}
	//	if ((gear == 4) && ((speed >= 40) && (speed <= 90))) {
	//		transmission == gear;
	//		return true;
	//	}
	//	if ((gear == 3) && ((speed >= 30) && (speed <= 60))) {
	//		transmission = gear;
	//		return true;
	//	}
	//	if ((gear == 2) && ((speed >= 20) && (speed <= 50))) {
	//		transmission = gear;
	//		return true;
	//	}
	//	if ((gear == 1) && ((speed >= 0) && (speed <= 30) && (direction >= 0))) {
	//		transmission = gear;
	//		return true;
	//	}
	//	if ((gear == 1) && ((direction == -1) && (speed == 0))) {
	//		transmission = gear;
	//		return true;
	//	}
	//	if (gear == 0) {
	//		transmission = gear;
	//		return true;
	//	}
	//	if ((gear == -1) && (speed == 0)) {
	//		transmission = gear;
	//		return true;
	//	}
	//}
	//return false;
}

bool Car::SetSpeed(short m_speed) {
	std::map<short, std::pair<int, int>> speed_map = {
	{5, {50, 150}},
	{4, {40, 90}},
	{3, {30, 60}},
	{2, {20, 50}},
	{1, {0, 30}},
	{-1, {0, 20}}
	};

	auto it = speed_map.find(transmission);
	if (it != speed_map.end() && m_speed >= it->second.first && m_speed <= it->second.second) {
		speed = m_speed;
		direction = (transmission == -1) ? -1 : 1;
		return true;
	}

	if (transmission == 0) {
		if (speed == 0) {
			std::cout << NSPEED << std::endl;
			return false;
		}
		if (std::max((int)0, speed - m_speed) == 0) {
			speed = 0;
			direction = 0;
		}
		else {
			speed -= m_speed;
		}
		return true;
	}
	else {
		if (m_speed <= it->second.first) {
			std::cout << MINSPEED << std::endl;
		}
		if (m_speed >= it->second.second) {
			std::cout << MAXSPEED << std::endl;
		}
		return false;
	}
	//if ((transmission == 5) && ((m_speed <= 150) && (m_speed >= 50))) {
	//	speed = m_speed;
	//	direction = 1;
	//	return true;
	//}
	//if ((transmission == 4) && ((m_speed <= 90) && (m_speed >= 40))) {
	//	speed = m_speed;
	//	direction = 1;
	//	return true;
	//}
	//if ((transmission == 3) && ((m_speed <= 60) && (m_speed >= 30))) {
	//	speed = m_speed;
	//	direction = 1;
	//	return true;
	//}
	//if ((transmission == 2) && ((m_speed <= 50) && (m_speed >= 20))) {
	//	speed = m_speed;
	//	direction = 1;
	//	return true;
	//}
	//if ((transmission == 1) && ((m_speed <= 30) && (m_speed >= 0))) {
	//	speed = m_speed;
	//	direction = 1;
	//	return true;
	//}
	//if (transmission == 0) {
	//	return false;
	//}
	//if ((transmission == -1) && ((m_speed <= 20) && (m_speed >= 0))) {
	//	speed = m_speed;
	//	direction = -1;
	//	return true;
	//}

	//return false;
}

void Info(Car& jeep) {
	std::cout << (jeep.IsTurnedOn() ? "On" : "Off") << "\n";

	if (jeep.GetDirection() == -1) std::cout << "backward" << "\n";
	if (jeep.GetDirection() == 0) std::cout << "standing still" << "\n";
	if (jeep.GetDirection() == 1) std::cout << "forward" << "\n";

	std::cout << "speed: " << jeep.GetSpeed() << "\n";
	std::cout << "gear: " << jeep.GetGear() << "\n";
}


//сделать значения проверок диапазона скоростеф и передач в виде map.