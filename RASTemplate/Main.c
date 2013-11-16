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
	double error;
	double last_error = 0;
	int i;
	float line[8];
	InitializeMCU();
	ls = InitializeGPIOLineSensor(PIN_B5, PIN_D0, PIN_D1, PIN_D2, PIN_D3, PIN_E0, PIN_C6, PIN_C7);
	motor[0] = InitializeMotor(PIN_B7, PIN_B6, true, true); //left
	motor[1] = InitializeMotor(PIN_C5, PIN_C4, true, true); //right
	rmSpeed = -.3;
	lmSpeed = -.3;
	SetMotor(motor[0], lmSpeed);
	SetMotor(motor[1], rmSpeed);
	mLeft = lmSpeed;
	mRight = rmSpeed;
	while(1){
		LineSensorReadArray(ls, line);
		for (i = 0; i < 8; i++){
			if (line[i] > 0.3){
				line[i] = 1;
			}
			else{
				line[i] = 0;
			}
		}
		error = (-3 * line[0]) + (-2 * line[1]) + (-1 * line[2]) + (0 * line[3]) + (0 * line[4]) + 
		(1 *  line[5]) + (2 * line[6]) + (3 * line[7]);
		last_error = error;
		mSpeed = error * .07;
		mLeft = fabs(mSpeed + fabs(lmSpeed)) * -1;
		mRight = fabs(fabs(rmSpeed) - mSpeed) * -1;
		Printf("mLeft: %0.01f   mRight: %0.01f\n", mLeft, mRight);
		SetMotor(motor[0], mLeft);
		SetMotor(motor[1], mRight);
	}
}

