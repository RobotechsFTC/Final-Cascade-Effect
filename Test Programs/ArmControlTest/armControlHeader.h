//----------------------------------------------------------------------
// (C) MVMS Robotechs Team #8742
//  File Nmae : arm_control_header.h
//  Version   : 2.16
//  Function  : Implements arm control functions
//----------------------------------------------------------------------
int cur_shoulder_count;
int cur_shoulder_degree;
int count;
int STOP=0;
void set_shoulder(int degree)
{
  count = degree* 33;
	cur_shoulder_count = nMotorEncoder[Arm];
	if(count > nMotorEncoder[Arm])
	{
		while(count > nMotorEncoder[Arm])
		{
			motor[Arm] = 60;
		}
		motor[Arm] = 0;
	}else
	{
		while(count -count/5 < nMotorEncoder[Arm])
		{
			motor[Arm] = -64;
			wait10Msec(5);
			motor[Arm] = 0;
			wait10Msec(5);
			cur_shoulder_count = nMotorEncoder[Arm];
		}
		while(count  < nMotorEncoder[Arm])
		{
			motor[Arm] = -30;
			wait10Msec(10);
			motor[Arm] = 0;
			wait10Msec(5);
		}
		motor[Arm] = 0;
	}
	cur_shoulder_degree = degree;
	nMotorEncoder[Arm]=degree*33;
}

void handleTouch(int touch,int lastTouch){
	if(touch!=0&&lastTouch==0){
		STOP = 1;//stop the motor
	}
	if(lastTouch!=0&&touch==0){
		nMotorEncoder[Arm]=0;
		cur_shoulder_degree = 0;
		STOP = 0;
	}
}

void harvOpen()
{
	servo[Harvey1] = 255;
	servo[Harvey2] = 0;
}

void harvClosed()
{
	servo[Harvey1] = 0;
	servo[Harvey2] = 255;
}

void rackyOut(int timeInMili)
{
	servo[Racky] = 0;
	wait(timeInMili, milliseconds);
	servo[Racky]=127;
}

void rackyIn(int timeInMili)
{
	servo[Racky] = 255;
	wait(timeInMili, milliseconds);
	servo[Racky]=127;
}

void catcherTilt(int degree)
{
	servo[l_tilt] = degree;
	servo[r_tilt] = 255-degree;
}
