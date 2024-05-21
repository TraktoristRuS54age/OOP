#include "stdafx.h"
#include "CCone.h"
#include "CCylinder.h"
#include "CParallelepiped.h"
#include "CSphere.h"
#include "CCompound.h"
#include "CBodyControl.h"

int main() {
	vector<shared_ptr<CBody>> bodies;

	CBodyControl bodiesControl(bodies, cin, cout);
	bodiesControl.ReadBodies();
	bodiesControl.WriteBodies();
	bodiesControl.WriteHaviestBody();
	bodiesControl.WriteLightestBodyInWater();

	return 0;
}