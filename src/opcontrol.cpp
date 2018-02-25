/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */
void operatorControl() {
	int leftJoystickValue, rightJoystickValue;
	int armSpeed;

	Arm*            arm           = Arm::getInstance();
	Claw*           claw          = Claw::getInstance();
	Base*           base          = Base::getInstance();
	MogoCollector*  mogoCollector = MogoCollector::getInstance();

	while (true) {
		// Joystick control
		leftJoystickValue = -threshold(joystickGetAnalog(1, 3));
		rightJoystickValue = -threshold(joystickGetAnalog(1, 4));
		base->moveBase(leftJoystickValue + rightJoystickValue, leftJoystickValue - rightJoystickValue);

		// Arm control
		//armSpeed = ((joystickGetDigital(2, 6, JOY_DOWN) - joystickGetDigital(2, 6, JOY_UP)) * 50);
		armSpeed = -threshold(joystickGetAnalog(1, 2));
		arm->moveArm(armSpeed);

		// Claw control
		if (joystickGetDigital(1, 5, JOY_UP)) {
			claw->setClaw(true);
		} else if (joystickGetDigital(1, 5, JOY_DOWN)) {
			claw->setClaw(false);
		}

		// Mogo Collector control
		mogoCollector->moveCollector((joystickGetDigital(1, 6, JOY_UP) - joystickGetDigital(1, 6, JOY_DOWN)) * 50);

		delay(10); // Small delay
	}
}
