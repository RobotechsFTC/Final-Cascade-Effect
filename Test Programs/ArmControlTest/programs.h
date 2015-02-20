void initializeRobot()
{
	nMotorEncoder[Arm]=0;
	cur_shoulder_degree = 0;
	cur_shoulder_count = 0;

	return;
}

void teleopArm(){
	int adval=1;
	int lastTouch = 1;
  	initializeRobot();

  	//waitForStart();   // wait for start of tele-op phase
	  getJoystickSettings(joystick);
	  if(joy1Btn(4)){
	  	set_shoulder(cur_shoulder_degree+adval);
	  }else if(joy1Btn(2)&&STOP==0){
	  	set_shoulder(cur_shoulder_degree-adval);
	  }

	  if(SensorValue(touchSensor) != 0){
	  	handleTouch(SensorValue(touchSensor),lastTouch);
	  }
	  lastTouch = ServoValue(touchSensor);
	  wait1Msec(1);
}
