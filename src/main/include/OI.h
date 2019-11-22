/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

//XBox button/axis values
    const int XBOX_AXIS_LEFT_X = 0;
    const int XBOX_AXIS_LEFT_Y = 1;

    const int XBOX_AXIS_RIGHT_X = 4;
    const int XBOX_AXIS_RIGHT_Y = 5;

    const int XBOX_AXIS_RIGHT_TRIGGER = 3;
    const int XBOX_AXIS_LEFT_TRIGGER = 2;

    const int XBOX_BUTTON_A = 1;
    const int XBOX_BUTTON_B = 2;
    const int XBOX_BUTTON_X = 3;
    const int XBOX_BUTTON_Y = 4;

    const int XBOX_BUTTON_LEFT_BUMPER = 5;
    const int XBOX_BUTTON_RIGHT_BUMPER = 6;
    
    const int NEAR_TARGET = 1;

    const int XBOX_BUTTON_TWO_WINDOWS = 7;
    const int XBOX_BUTTON_THREE_LINES = 8;

    const int XBOX_BUTTON_LEFT_JOYSTICK_PRESSED = 9;
    const int XBOX_BUTTON_RIGHT_JOYSTICK_PRESSED = 10;

    const double JOYSTICK_DEADZONE = 0.1;
    const double TARGET_CENTERX_MUL = 1;
    const double TARGET_DISTANCE_MUL = 1;
//Logitech Control button values
    const int LOGITECH_RIGHT_TRIGGER = 8;
    const int LOGITECH_LEFT_TRIGGER = 7;

    const int LOGITECH_BUTTON_A = 2;
    const int LOGITECH_BUTTON_B = 3;
    const int LOGITECH_BUTTON_X = 1;
    const int LOGITECH_BUTTON_Y = 4;

    const int LOGITECH_BUTTON_LEFT_BUMPER = 5;
    const int LOGITECH_BUTTON_RIGHT_BUMPER = 6;
class OI {
 public:
  OI();
};
