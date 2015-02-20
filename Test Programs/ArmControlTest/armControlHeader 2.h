//----------------------------------------------------------------------
// (C) MVMS Robotechs Team #8742
//  File Nmae : arm_control_header.h
//  Version   : 2.16
//  Function  : Implements arm control functions
//----------------------------------------------------------------------
int cur_shoulder_count;
int cur_shoulder_degree;
int count;

void set_shoulder(int degree)
{
	count = degree* 33;
	cur_shoulder_count = nMotorEncoder[Arm];
	if(count > nMotorEncoder[Arm])
	{
		while(count-count/5 > nMotorEncoder[Arm])
		{
			motor[Arm] = 60;
		}
		while(count > nMotorEncoder[Arm])
		{
			motor[Arm] = 30;
		}
		motor[Arm] = 0;
	}
	else
	{
		while(count -count/5 < nMotorEncoder[Arm])
		{
			motor[Arm] = -60;
			wait10Msec(10);
			motor[Arm] = 0;
			wait10Msec(12);
		}
		while(count  < nMotorEncoder[Arm])
		{
			motor[Arm] = -30;
			wait10Msec(10);
			motor[Arm] = 0;
			wait10Msec(12);
		}
		motor[Arm] = 0;
	}
}

void set_shoulder_degree(unsigned int degree){
	//moves five until you need to go less than 2
	while(abs(cur_shoulder_degree-degree)>2){
		if(cur_shoulder_degree-degree>0){
			set_shoulder(cur_shoulder_degree-2);
			}else{
			set_shoulder(cur_shoulder_degree+2);
		}
	}
	//moves the rest
	if(cur_shoulder_degree-degree!=0)
		set_shoulder(degree);
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
}

void rackyIn(int timeInMili)
{
	servo[Racky] = 255;
	wait(timeInMili, milliseconds);
}

void catcherTilt(int degree)
{
	int n = degree;
	int x = n;
	int y = 255 - n;
	servo[l_tilt] = x;
	servo[r_tilt] = y;
}
