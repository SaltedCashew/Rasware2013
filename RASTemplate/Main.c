#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/common.h>

// The 'main' function is the entry point of the program
void delay(int);
void SetPin(tPin, tBoolean);
int main(void) {
	tMotor *motor[2];
	InitializeMCU();
	motor[0] = InitializeMotor(PIN_F3, PIN_F2, true, false);
	motor[1] = InitializeMotor(PIN_B7, PIN_B6, true, false);
  while (1) {		
		SetMotor(motor[0], -0.25);
		SetMotor(motor[1], -0.25);
	}
}
