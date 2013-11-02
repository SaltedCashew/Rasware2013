#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/linesensor.h>
#include <RASLib/inc/i2c.h>
#include <RASLib/inc/common.h>
#include <RASLib/inc/adc.h>


void delay(int);
void SetPin(tPin, tBoolean);




int main(void) {

	tADC *adc[4];
	tMotor *motor[2];
	float ADCValue;
	float lmSpeed;
	float rmSPeed;

	InitializeMCU();

	motor[0] = InitializeMotor(PIN_F1, PIN_F0, true, true); //left wheel
	motor[1] = InitializeMotor(PIN_B7, PIN_B6, true, true); //right wheel
	adc[0] = InitializeADC(PIN_D0);

lmSpeed = .04
rmSpeed = .03
	SetMotor(motor[1], lmSpeed); 
			SetMotor(motor[0], smSpeed);

	
	while(1){
Printf("start\n");
		ADCValue = ADCRead(adc[0]);
		
	// SetMotor (motor[0], 1 - (ADCValue)); //change the right wheel only
  
	// Printf("IR1 values: %d\t", (ADCValue));	
 //  Printf(" %d\n", (int)(ADCValue*1000));

	
	
	
		if (ADCValue >= 800){
			SetMotor(motor[1], rmSpeed -0.1); //turn right
			SetMotor(motor[0], lmSpeed +0.1);
		}
		
		if (ADCValue <= 	100) {
			SetMotor(motor[1], rmSpeed+.1); //turn Left 
			SetMotor(motor[0], lmSpeed-.1);
		}
		
		
		
		else { 
			SetMotor(motor[1], rmSpeed); 
			SetMotor(motor[0], lmSpeed);
			

		Wait(.01);
		}
		
	
	}
}

