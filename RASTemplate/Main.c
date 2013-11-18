#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/linesensor.h>
#include <RASLib/inc/i2c.h>
#include <RASLib/inc/common.h>
#include <RASLib/inc/adc.h>
#include <RASLib/inc/encoder.h>
#include <math.h>


void delay(int);
void SetPin(tPin, tBoolean);


tLineSensor *ls;

int main(void) {
	tMotor *motor[2];
	double lmSpeed;
	double rmSpeed;
	double mSpeed;
	double mLeft, mRight;
	double sum;
	double error;
	double last_error = 0;
	int i;
	int flag = 0;
	float line[8];
	InitializeMCU();
	ls = InitializeGPIOLineSensor(PIN_B5, PIN_D0, PIN_D1, PIN_D2, PIN_D3, PIN_E0, PIN_C6, PIN_C7);
	motor[0] = InitializeMotor(PIN_B7, PIN_B6, true, false); //left
	motor[1] = InitializeMotor(PIN_C5, PIN_C4, true, false); //right
	rmSpeed = .2;
	lmSpeed = .2;
	SetMotor(motor[0], lmSpeed);
	SetMotor(motor[1], rmSpeed);
	mLeft = lmSpeed;
	mRight = rmSpeed;
	while(1){
		LineSensorReadArray(ls, line);
		Printf("[");
		for (i = 0; i < 8; i++){
			if (line[i] > 0.3){
				line[i] = 1;
			}
			else{
				line[i] = 0;
			}
			Printf(" %f", line[i]);
		}
		Printf("]\n");
		sum = line[0] + line[1] + line[2] + line[3] + line[4] + line[5] + line[6] + line[7];
		if (sum == 1 & line[0] == 1){
			error = -100;
		}
		else if (sum == 1 & line[7] == 1){
			error = 100;
		}
		else{
			error = (-3 * line[0]) + (-2 * line[1]) + (-1 * line[2]) + (0 * line[3]) + (0 * line[4]) + 
			(1 *  line[5]) + (2 * line[6]) + (3 * line[7]);
		}
		

		if( fabs(error) >= 3 && flag == 1 )
		{
			SetMotor( motor[0], 0 );
			SetMotor( motor[1], 0 );
			flag = 0;
			Wait(0.05);
		}
		
			last_error = error;
			mSpeed = (error * .15); // + (((last_error - error) / 2) * 5000);
			mLeft = mSpeed + lmSpeed;
			mRight = rmSpeed - mSpeed;
			Printf("mLeft: %0.01f   mRight: %0.01f\n", mLeft, mRight);
		//		Wait(1);
		
		if( fabs(error) < 3 )
		{
			mLeft = 0.3;
			mRight = 0.3; 
			flag = 1;	
		}
		
			SetMotor(motor[0], mLeft);
			SetMotor(motor[1], mRight);
		
	}
}

