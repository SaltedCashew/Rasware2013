#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/linesensor.h>
#include <RASLib/inc/i2c.h>
#include <RASLib/inc/common.h>
#include <RASLib/inc/adc.h>
#include <RASLib/inc/encoder.h>


void delay(int);
void SetPin(tPin, tBoolean);




int main(void) {

	tMotor *motor[2];
	tEncoder *encoder[2];
	int waiting = 0;
	double lmSpeed;
	double rmSpeed;
	InitializeMCU();
	motor[0] = InitializeMotor(PIN_B7, PIN_B6, true, true); //left
	motor[1] = InitializeMotor(PIN_C5, PIN_C4, true, true); //right
	rmSpeed = -.48;
	lmSpeed = -.48;
	SetMotor(motor[0], lmSpeed);
	SetMotor(motor[1], rmSpeed);
//	encoder[0] = InitializeEncoder(PIN_A3, PIN_E1, false);
	encoder[1] = InitializeEncoder(PIN_E3, PIN_A7, false);
	while(1){
//		Printf("Encoder 1: %d\n", GetEncoder(encoder[1]));
/*		while(GetEncoder(encoder[1]) < (7800 * 11)){
			SetMotor(motor[0], 0);
			SetMotor(motor[1], rmSpeed);
			Wait(0.1);
			SetMotor(motor[0], lmSpeed);
			SetMotor(motor[1], 0);
			Wait(0.105);
		}
		*/
		if (GetEncoder(encoder[1]) >= ((7500 + waiting) * 11)){
			SetMotor(motor[0], lmSpeed);
			SetMotor(motor[1], 0);
			Wait(0.6);
			ResetEncoder(encoder[1]);
			waiting += 500;
		}
		SetMotor(motor[0], lmSpeed);
		SetMotor(motor[1], rmSpeed);
	}
}

