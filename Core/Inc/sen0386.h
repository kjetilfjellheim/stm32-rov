
#ifndef __SEN0386_H
#define __SEN0386_H

#include <stdio.h>

#define SEN0386_READ_BUFFER_SIZE 100
#define SEN0386_UNDEDFINED 	-9999999

typedef struct {
	float accXData;
	float accYData;
	float accZData;
} Acceleration;

typedef struct {
	float angleVelX;
	float angleVelY;
	float angleVelZ;
} AngVel;

typedef struct {
	float roll;
	float pitch;
	float yaw;
} Angle;

typedef struct {
	Acceleration acceleration;
	AngVel angularVelocity;
	Angle angle;
} Sen0386Data;

Sen0386Data getSensorInput(uint8_t* data);

#endif
