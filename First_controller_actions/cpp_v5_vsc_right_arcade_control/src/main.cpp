/* ---------------------------------------------------------------------------- */
/*                                                                              */    
/*    Project:        Right Arcade Control                                      */                  
/*    Module:         main.cpp                                                  */
/*    Author:         VEX                                                       */
/*    Created:        Fri Aug 05 2022                                           */
/*    Description:    This example will use the right X/Y Controller            */
/*                    axis to control the Clawbot.                              */
/*                                                                              */    
/*    Configuration:  V5 Clawbot (Individual Motors)                            */
/*                    Controller                                                */
/*                    Claw Motor in Port 3                                      */
/*                    Arm Motor in Port 8                                       */
/*                    Left Motor in Port 1                                      */
/*                    Right Motor in Port 10                                    */
/*                                                                              */    
/* ---------------------------------------------------------------------------- */

// Include the V5 Library
#include "vex.h"

// Allows for easier use of the VEX Library
using namespace vex;

// Brain should be defined by default
brain Brain;

// Robot configuration code.
motor ClawMotor = motor(PORT3, ratio18_1, false);
motor ArmMotor = motor(PORT8, ratio18_1, false);

controller Controller1 = controller(primary);

motor LeftMotor = motor(PORT1, ratio18_1, false);
motor RightMotor = motor(PORT10, ratio18_1, true);

int main() {
  // Begin project code.
  // Main Controller loop to set motors to controller axis postiions
  while (true) {
    LeftMotor.setVelocity((Controller1.Axis2.position() + Controller1.Axis1.position()), percent);
    RightMotor.setVelocity((Controller1.Axis2.position() - Controller1.Axis1.position()), percent);
    LeftMotor.spin(forward);
    RightMotor.spin(forward);

    wait(5, msec);
  }

  return 0;
}

