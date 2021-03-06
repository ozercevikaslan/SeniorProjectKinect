// SeniorProjectC++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Device.h"
#include <iostream>
#include <thread>
using namespace std;

int main()
{
	// Creating an instance to our concrete class named Device which is our interface to the Kinect sensor.
	Device* newDev = new Device();
	// Initialization of the sensor
	bool initialization = newDev->initKinect();
	if (!initialization) {
		cout << "Kinect device could not be successfully opened !" << endl;
		return 0;
	}
	// Let the Kinect sensor to get ready
	Sleep(5000);
	// Live visualization of the joints
	thread drawSkeletonThread(&Device::drawJoints, newDev);
	drawSkeletonThread.join();
	// thread t1(&Device::recordBodyData, newDev);
	// thread t2(&Device::recordColorData, newDev);
	// t1.join();
	// t2.join();

	newDev->sensor->Close();

	safeRelease(newDev->sensor);

	return 0;
}

