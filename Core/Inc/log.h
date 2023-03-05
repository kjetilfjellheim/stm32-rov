/*
 * log.h
 *
 *  Created on: Mar 4, 2023
 *      Author: kjeti
 */

#ifndef INC_LOG_H_
#define INC_LOG_H_

typedef struct {
	int time;
	int command;
	int speedLeft;
	int speedRight;
	int commandToType;
	int commandTypeValue;
	int maxPitchLowVal;
	int maxPitchHighVal;
	int maxYawLowVal;
	int maxYawHighVal;
	float accXData;
	float accYData;
	float accZData;
	float angleVelX;
	float angleVelY;
	float angleVelZ;
	float roll;
	float pitch;
	float yaw;
} Log;

#endif /* INC_LOG_H_ */
