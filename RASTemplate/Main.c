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
	double lmSpeed;
	double rmSpeed;
	InitializeMCU();
	motor[0] = InitializeMotor(PIN_B7, PIN_B6, true, true); //left
	motor[1] = InitializeMotor(PIN_C5, PIN_C4, true, true); //right
	encoder[0] = InitializeEncoder(PIN_B5, PIN_D1, false);
	encoder[1] = InitializeEncoder(PIN_E3, PIN_A7, false);
	rmSpeed = -.4;
	lmSpeed = -.3;
//	SetMotor(motor[0], lmSpeed);
//	SetMotor(motor[1], rmSpeed);
	while(1){
		Printf("Encoder 0: %d   Encoder 1: %d\n", GetEncoder(encoder[0]), GetEncoder(encoder[1]));
		Wait(1);
	}
}

