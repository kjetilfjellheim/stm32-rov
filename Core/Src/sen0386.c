/*
 * sen0386.c
 *
 *  Created on: Feb 28, 2023
 *      Author: kjeti
 */
#include "sen0386.h"

#define NOT_FOUND 	-1
#define SEN0386_XL 2
#define SEN0386_XH 3
#define SEN0386_YL 4
#define SEN0386_YH 5
#define SEN0386_ZL 6
#define SEN0386_ZH 7

const uint8_t SEN0386_HEADERACC = 0x51;
const uint8_t SEN0386_HEADERANGVEL = 0x52;
const uint8_t SEN0386_HEADERANGLE = 0x53;
const uint8_t SEN0386_PACKET_HEADER = 0x55;

short convertBytes(uint8_t highByte, uint8_t lowByte) {
	return (short)highByte<<lowByte;
}

int getPacketStart(uint8_t* data, uint8_t packetHeader) {
	for (int index = 0; index < SEN0386_READ_BUFFER_SIZE; index++) {
		if (data[index]==SEN0386_PACKET_HEADER && data[index+1]==packetHeader) {
			return index;
		}
	}
	return NOT_FOUND;
}

short getShort(uint8_t highByte, uint8_t lowByte) {
	return (short)((highByte << 8) | lowByte);
}

Acceleration getAccelerations(uint8_t* data) {
	Acceleration acceleration;
	int packetStart = getPacketStart(data, SEN0386_HEADERACC);
	if (packetStart != NOT_FOUND) {
		acceleration.accXData = (getShort(data[SEN0386_XH + packetStart], data[SEN0386_XL + packetStart]) / 32768.0) * 16.0 * 9.8;
		acceleration.accYData = (getShort(data[SEN0386_YH + packetStart], data[SEN0386_YL + packetStart]) / 32768.0) * 16.0 * 9.8;
		acceleration.accZData = (getShort(data[SEN0386_ZH + packetStart], data[SEN0386_ZL + packetStart]) / 32768.0) * 16.0 * 9.8;
	} else {
		acceleration.accXData = SEN0386_UNDEDFINED;
		acceleration.accYData = SEN0386_UNDEDFINED;
		acceleration.accZData = SEN0386_UNDEDFINED;
	}
	return acceleration;
}

AngVel getAngVels(uint8_t* data) {
	AngVel angVel;
	int packetStart = getPacketStart(data, SEN0386_HEADERANGVEL);
	if (packetStart != NOT_FOUND) {
		angVel.angleVelX = (getShort(data[SEN0386_XH + packetStart], data[SEN0386_XL + packetStart]) / 32768.0) * 2000.0;
		angVel.angleVelY = (getShort(data[SEN0386_YH + packetStart], data[SEN0386_YL + packetStart]) / 32768.0) * 2000.0;
		angVel.angleVelZ = (getShort(data[SEN0386_ZH + packetStart], data[SEN0386_ZL + packetStart]) / 32768.0) * 2000.0;
	} else {
		angVel.angleVelX = SEN0386_UNDEDFINED;
		angVel.angleVelY = SEN0386_UNDEDFINED;
		angVel.angleVelZ = SEN0386_UNDEDFINED;
	}
	return angVel;
}

Angle getAngles(uint8_t* data) {
	Angle angle;
	int packetStart = getPacketStart(data, SEN0386_HEADERANGLE);
	if (packetStart != NOT_FOUND) {
		angle.roll = getShort(data[SEN0386_XH + packetStart], data[SEN0386_XL + packetStart]) / 32768.0 * 180.0;
		angle.pitch = getShort(data[SEN0386_YH + packetStart], data[SEN0386_YL + packetStart]) / 32768.0 * 180.0;
		angle.yaw = getShort(data[SEN0386_ZH + packetStart], data[SEN0386_ZL + packetStart]) / 32768.0 * 180.0;
	} else {
		angle.roll = SEN0386_UNDEDFINED;
		angle.pitch = SEN0386_UNDEDFINED;
		angle.yaw = SEN0386_UNDEDFINED;
	}
	return angle;
}

Sen0386Data getSensorInput(uint8_t* data) {
	Sen0386Data sen0386Data;
	sen0386Data.acceleration = getAccelerations(data);
	sen0386Data.angularVelocity = getAngVels(data);
	sen0386Data.angle = getAngles(data);
	return sen0386Data;
}
