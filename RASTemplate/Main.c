#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/linesensor.h>
#include <RASLib/inc/i2c.h>
#include <RASLib/inc/common.h>
// The 'main' function is the entry point of the program
void delay(int);
void SetPin(tPin, tBoolean);
tLineSensor *ls;
int main(void) {
	unsigned char read;
	tI2C *bus;
//	tMotor *motor[2];
	InitializeMCU();
	bus = InitializeI2C(PIN_B3, PIN_B2);
	ls = InitializeLineSensor(bus, 0);
/*	motor[0] = InitializeMotor(PIN_C5, PIN_C4, true, false); //right wheel
	motor[1] = InitializeMotor(PIN_B7, PIN_B6, true, false); //left wheel
	SetMotor(motor[0], -0.20);
	SetMotor(motor[1], -0.20); */
	while(1){
		read = LineSensorRead(ls, 0.75);
		Printf("%x ", read);
		Wait(1);
/*		if (read >= 1 && read <= 40){
			SetMotor(motor[0], -0.30); //turn left
			SetMotor(motor[1], -0.10);
		}
		else if (read >= 150){
			SetMotor(motor[1], -0.20); //turn right
			SetMotor(motor[0], -0.10);
		}
		else{
			SetMotor(motor[0], -0.20);
			SetMotor(motor[1], -0.20);
		}
		*/
	}
}
