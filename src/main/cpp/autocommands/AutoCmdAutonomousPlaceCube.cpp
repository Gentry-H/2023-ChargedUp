// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdAutonomousPlaceCube.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
AutoCmdAutonomousPlaceCube::AutoCmdAutonomousPlaceCube(SubVerticalElevator* subVerticalElevator, SubTurret* subTurret, SubHorizontalElevator* subHorizontalElevator, SubClawWrist* subClawWrist, frc::Timer* timer) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand{}, BarCommand{});
  AddCommands(
//    AutoCmdPlaceCube{subVerticalElevator, subTurret, subHorizontalElevator, subClawWrist, timer},
    AutoCmdVerticalElevatorServoToPosition{subVerticalElevator, VERTICAL_ELEV_POS_CUBE_NODE_UPPER, 50000},
    AutoCmdTurretServoToDegree{subTurret, 183, 160},
    AutoCmdHorizontalElevatorServoToPosition{subHorizontalElevator, 34, 26},
    AutoCmdWristServoToPosition{subClawWrist, 10.5, 7.5},
    AutoCmdIntakeSpin{subClawWrist, 0.6, timer, 0.1},
    //SeqCmdTurretAndElevatorsServoToHome{subClawWrist, subHorizontalElevator, subTurret, subVerticalElevator}
    AutoCmdWristServoToPosition{subClawWrist, 0, 20},
    AutoCmdHorizontalElevatorServoToPosition{subHorizontalElevator, 0, 8},
    AutoCmdTurretServoToDegree{subTurret, 0, 9},
    AutoCmdVerticalElevatorServoToPosition{subVerticalElevator, 2000, 100000}
  );
}