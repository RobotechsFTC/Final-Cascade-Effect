#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTServo,  HTMotor)
#pragma config(Sensor, S3,     IR,             sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     motorF,        tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorD,        tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C4_1,     motorE,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     motorG,        tmotorTetrix, PIDControl, encoder)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_1,    servo7,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_2,    servo8,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo9,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo10,              tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo11,              tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo12,              tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

while(true){
	if(SensorValue[IR]==5||SensorValue[IR]==0){
		nxtDisplayCenteredTextLine(2,"middle");
	}else if(SensorValue[IR]>5){
  	nxtDisplayCenteredTextLine(2,"right");
	}else if(SensorValue[IR]<5){
		nxtDisplayCenteredTextLine(2,"left");
	}
}
/*
	tHTIRS2 irSeeker;
	initSensor(&irSeeker, S3);
	irSeeker.mode = (irSeeker.mode == DSP_1200) ?  DSP_600 : DSP_1200;
	while(true)
	{
		initSensor(&irSeeker, S1);
		displayCenteredTextLine(1,"%d", irSeeker.dcDirection);
		if (irSeeker.enhStrength < 200){
			move_fwd_wait(40,100);

		}
		else {
			break;
		}
	}*/
	//move_fwd_wait(40,610);
	//move_bck_wait(40,610);
	//turn_rht_wait(40,90);
	//urn_lft_wait(40,90);
	//move_rht_wait(40,200);
	//move_lft_wait(40,200);

}
