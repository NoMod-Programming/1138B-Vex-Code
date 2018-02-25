/** @file Constants.h
 * @brief Provides constants used throughout the entire code. Contains user-readable motor names
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include "main.h"
#include "subsystems/Claw.h"
#include "subsystems/Arm.h"
#include "subsystems/Base.h"

// Motors
const int baseCollectorLeft = 1;
const int leftBackMotor = 2;
const int leftFrontMotor = 3;
const int leftShoulderMotor = 4;

const int rightShoulderMotor = 7;
const int rightFrontMotor = 8;
const int rightBackMotor = 9;
const int baseCollectorRight = 10;

// Analog Sensors
const int autonPotentiometer = 1;
const int gyroSensor = 2;

// Digital Sensors
const int clawPneumatic = 1;

// Other Sensors
const float rotationsPerInch = 31.400156410256;

#endif
