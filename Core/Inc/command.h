/*
 * command.h
 *
 *  Created on: Mar 5, 2023
 *      Author: kjeti
 */

#ifndef INC_COMMAND_H_
#define INC_COMMAND_H_

#define MAX_COMMAND_SIZE 100

#define COMMAND_NONE			0
#define COMMAND_ROTATE_RIGHT	1
#define COMMAND_ROTATE_LEFT		2
#define COMMAND_TURN_RIGHT		3
#define COMMAND_TURN_LEFT		4
#define COMMAND_FORWARD			5
#define COMMAND_REVERSE			6

#define COMMAND_TYPE_SECONDS		1
#define COMMAND_TYPE_MILLISECONDS	2
#define COMMAND_TYPE_DIRECTION		3

#define COMMAND_STATUS_UNSTARTED	1
#define COMMAND_STATUS_STARTED		2
#define COMMAND_STATUS_COMPLETED	3

#define COMMAND_ALLOW_OVERRIDE_NO	0
#define COMMAND_ALLOW_OVERRIDE_YES	1

struct {
	int command;
	int speedLeft;
	int speedRight;
	int commandToType;
	int commandTypeValue;
	int maxPitchLowVal;
	int maxPitchHighVal;
	int maxYawLowVal;
	int maxYawHighVal;
	int status;
	int overrrideAllowed;
} Command, Commands[MAX_COMMAND_SIZE];

#endif /* INC_COMMAND_H_ */
