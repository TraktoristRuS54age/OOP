#include "Header.h"

const std::string HELLO = "Hello! You can test the car's performance. Here is a list of available commands:";
const std::string INSTRUCTION = "You want? (fill in a word from the list)";
const std::string INFO = "Info";
const std::string ON = "EngineOn";
const std::string OFF = "EngineOff";
const std::string GEAR = "SetGear";
const std::string SPEED = "SetSpeed";
const std::string END = "End";
const std::string START = "Engine on";
const std::string STALLED = "Engine off";
const std::string TRANS = "Enter the specified gear from -1 to 5: ";
const std::string MTRANS = "Transmission changed";
const std::string SETSPEED = "Enter a value between 0 and 150: ";
const std::string MSPEED = "Speed changed";

int main()
{
	Car *jeep = new Car;
	std::cout << HELLO << std::endl;
	std::string answer = " ";
	short gear = 0, m_speed = 0;
	while (answer != END) {
		std::cout << INSTRUCTION << std::endl;
		std::cout << "\t" << INFO << "\n\t" << ON << "\n\t" << OFF << "\n\t" << GEAR << "\n\t" << SPEED << "\n\t" << END << "\n";
		std::cin >> answer;
		if (answer == INFO) {
			Info(*jeep);
		}
		if (answer == ON) {
			if (jeep->TurnOnEngine()) {
				std::cout << START << "\n";
			}
		}
		if (answer == OFF) {
			if (jeep->TurnOffEngine()) {
				std::cout << STALLED << "\n";
			}
		}
		if (answer == GEAR) {
			std::cout << TRANS;
			std::cin >> gear;
			if (jeep->SetGear(gear)) {
				std::cout << MTRANS << "\n";
			}
		}
		if (answer == SPEED) {
			std::cout << SETSPEED;
			std::cin >> m_speed;
			if (jeep->SetSpeed(m_speed)) {
				std::cout << MSPEED << "\n";
			}
		}
	}
	return 0;
}