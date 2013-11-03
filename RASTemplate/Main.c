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

	tADC *adc[1];
	tMotor *motor[2];
	float ADCValue;
	double lmSpeed;
	double rmSpeed;
	
	InitializeMCU();

motor[0] = InitializeMotor(PIN_B7, PIN_B6, true, false); //right motor
	motor[1] = InitializeMotor(PIN_C5, PIN_C4, true, true);
	
	//zero values
	//		SetMotor(motor[0], -.52);
	//  	SetMotor(motor[1], -.75); //-0.5 is stopped --
	adc[0] = InitializeADC(PIN_D0);

	
	
	lmSpeed = -.2;
	rmSpeed = -.3;
	
		//SetMotor(motor[0], rmSpeed);
		SetMotor(motor[1], lmSpeed);

	
	while(1){
Printf("start\n");
		ADCValue = ADCRead(adc[0]);
		
	
  
	// Printf("IR1 values: %d\t", (ADCValue));	
  //Printf(" %d\n", (int)(ADCValue*1000));
  // ADCValue *= 1000;
	SetMotor (motor[0], -1 + (ADCValue)); //change the right wheel only --
		// close distance = high value
	
	
	/*	if (ADCValue >= 650){
			SetMotor(motor[0], rmSpeed +.2); //turn right
			
		}
		
	//	else if (ADCValue <500 && ADCValue<800)
	//	{ SetMotor(motor[0], rmSpeed - 0.05) ;
	//	}
		
		else if (ADCValue < 	600) {
			
			SetMotor(motor[0], rmSpeed -.15); //turn left
		}
		
		
		else { 
			SetMotor(motor[1], lmSpeed); 
			SetMotor(motor[0], rmSpeed);
		}
*/
		Wait(.01);
		
		
	
	}
}

