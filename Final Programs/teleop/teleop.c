#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S2,     touchSensor,    sensorTouch)
#pragma config(Motor,  motorA,          harvey,        tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorE,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     motorD,        tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     motorF,        tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C4_1,     Arm,           tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C1_1,    Racky,                tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_3,    r_tilt,               tServoStandard)
#pragma config(Servo,  srvo_S1_C1_4,    l_tilt,               tServoStandard)
#pragma config(Servo,  srvo_S1_C1_5,    Harvey1,              tServoStandard)
#pragma config(Servo,  srvo_S1_C1_6,    Harvey2,              tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
#include "./basic_move_header_teleop.h"
#include "./armControlHeader.h"


void teleMove(short x2,short y2, short x1, short y1, short scale,short th){
	const short epsilon=30;
	const short movespeed=40/scale;
	const short turnspeed=40/scale;
	const short sidespeed=30/scale;
	if(th==6){
		move_rht(sidespeed,0);
		}else if(th==2){
		move_lft(sidespeed,0);
		}else if (x2>epsilon+20){
		turn_rht(turnspeed,0);
		}else if (x2<((-epsilon)+20)){
		turn_lft(turnspeed,0);
		}else if(y2>epsilon){
		move_fwd(movespeed,0);
		}else if(y2<-epsilon){
		move_bck(movespeed,0);
		}else{
		wheel_stop();
	}
}
void teleArm(bool four,bool two){
	if(joy1Btn(2)&&SensorValue[touchSensor]==0)
	{
		while(joy1Btn(2)&&SensorValue[touchSensor]==0){
			motor[Arm]=-40;
			wait1Msec(50);
			motor[Arm]=0;
			wait1Msec(50);
			getJoystickSettings(joystick);
		}
	}
	else if(joy1Btn(4))
	{
		motor[Arm]=30;
		while(joy1Btn(4)){getJoystickSettings(joystick);}
		motor[Arm]=0;
	}
}
void teleTilt(bool seven,bool eight){
	if(seven)
	{
		if(curTilt>1){
			catcherTilt(curTilt-1);
		}
	}
	else if(eight)
	{
		if(curTilt<254){
			catcherTilt(curTilt+1);
		}
	}
}


void flapper(bool one, bool three){
	if(one)
		harvOpen();
	else if(three)
		harvClosed();
}
void panic(bool bck){
	if(bck){
		motor[Arm]=20;
		wait1Msec(1500);
		motor[Arm]=0;
		catcherTilt(0);
	}
}
task main()
{
	catcherTilt(curTilt);
	while (true)
	{
		nxtDisplayCenteredTextLine(2,"Servo: %d",curTilt);
		getJoystickSettings(joystick);
		teleMove(joystick.joy1_x2,joystick.joy1_y2,joystick.joy1_x1,joystick.joy1_y1,1,joystick.joy1_TopHat);
		teleArm(joy1Btn(4),joy1Btn(2));
		flapper(joy1Btn(1),joy1Btn(3));
		teleTilt(joy1Btn(7),joy1Btn(8));
		panic(joy1Btn(9));
		wait1Msec(10);
	}
}
