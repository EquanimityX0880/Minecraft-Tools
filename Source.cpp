// Name: Ryan Zacharias
// Description: angle finder
// Date: 11/12/2020

#include<iostream>
#include<math.h> //atan, returns radians.
// rad = 180/PI
using namespace std;

constexpr auto PI = 3.14;

class trig {
	int ax, az, bx, bz, dx, dz = 0;
	double angle = 0;
	double mcAngle = 0;
	string quadrant = "";
public:

	void setCoords() {
		cout << "Set Coordinate Set A: " << endl
			<< "X position: ";
		cin >> ax;
		cout << "Z position: ";
		cin >> az;
		cout << endl
			<< "Set Coordinate Set B: " << endl
			<< "X position ";
		cin >> bx;
		cout << "Z position: ";
		cin >> bz;
		cout << endl;
	}

	void calculateTangentAngle() {
		dx = sqrt(pow(ax - bx, 2));
		dz = sqrt(pow(az - bz, 2));

		angle = abs(atan2(dz, dx)) * 180 / PI;
	}

	void calculateAngleMC() {
		if (ax < bx && az > bz) // Q.I
			mcAngle = -1 * angle - 90;
		else if (ax > bx && az > bz) // Q.II
			mcAngle = angle + 90;
		else if (ax > bx && az < bz)
			mcAngle = angle;
		else if (ax < bx && az < bz)
			mcAngle = -1 * angle;
	}

	void output() {
		cout << "Coordinate Set A: " << "(" << ax << "x, " << az << "z)" << endl;
		cout << "Coordinate Set B: " << "(" << bx << "x, " << bz << "z)" << endl;
		cout << "Coordinate Displacement: (" << dx << "x, " << dz << "z)" << endl << endl;

		cout << "Angle: " << angle << endl;
		cout << "Angle in MC: " << mcAngle << endl;
	}
}mc;

void main() {
	while (1) {
		mc.setCoords();
		mc.calculateTangentAngle();
		mc.calculateAngleMC();
		mc.output();
		system("pause");
		system("cls");
	}
}