#pragma once
#include <string>

int fuelRemaining(int initialFuel, int fuelConsumed);
int totalMass(int landerMass, int fuelRemainingMass);
double moonAcceleration(int landerHeight);
double weight(int landerMass, double moonGravity);
double netForce(int thrustForce, double moonGravity, int totalMass);
double netAcceleration(int thrustForce, double moonGravity, int totalMass, int fuelConsumedMass);
double velocity(double previousVelocity, double acceleration, int time);
double altitude(int previousAltitude, double previousVelocity, double acceleration, int time);