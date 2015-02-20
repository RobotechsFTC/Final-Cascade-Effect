#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorD,        tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     motorE,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     motorF,        tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     motorG,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C4_1,     Arm,           tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C1_1,    Racky,                tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_3,    r_tilt,               tServoStandard)
#pragma config(Servo,  srvo_S1_C1_4,    l_tilt,               tServoStandard)
#pragma config(Servo,  srvo_S1_C1_5,    Harvey1,              tServoStandard)
#pragma config(Servo,  srvo_S1_C1_6,    Harvey2,              tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(true)
	{
		if(nNxtButtonPressed == 1)
		{
			motor[Arm] = 60;
		}else if(nNxtButtonPressed == 2)
		{
			motor[Arm] = -35;
			}else{
			motor[Arm] = 0;
		}
		if(nNxtButtonPressed == 2)
		{
			motor[Arm] = -35;
			wait10Msec(5);
			motor[Arm] = 0;
			wait10Msec(5);
		}
		motor[Arm] = 0;
		int x = nMotorEncoder[Arm];
		int y = servoValue[l_tilt];
		writeDebugStreamLine("Arm is: %d", x);
		writeDebugStreamLine("l_tilt is: %d", y);
	}
}
/*
while(true)
{
if(nNxtButtonPressed == 1)
{
motor[Arm] = 60;
wait10Msec(20);
}
motor[Arm] = 0;
if(nNxtButtonPressed == 2)
{
motor[Arm] = -35;
wait10Msec(5);
motor[Arm] = 0;
wait10Msec(5);
}
motor[Arm] = 0;
int x = nMotorEncoder[Arm];
int y = servoValue[l_tilt];
writeDebugStreamLine("Arm is: %d", x);
writeDebugStreamLine("l_tilt is: %d", y);
}
*/