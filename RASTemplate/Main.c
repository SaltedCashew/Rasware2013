#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/linesensor.h>
#include <RASLib/inc/i2c.h>
#include <RASLib/inc/common.h>
#include <RASLib/inc/adc.h>
// The 'main' function is the entry point of the program

void delay(int);
void SetPin(tPin, tBoolean);
tLineSensor *ls;



int main(void) {
//	unsigned char read;
	tI2C *bus;
	tADC *adc[4];
	tMotor *motor[2];
	float ADCValue;

	InitializeMCU();
	bus = InitializeI2C(PIN_B3, PIN_B2);
	ls = InitializeLineSensor(bus, 0);
	motor[0] = InitializeMotor(PIN_F2, PIN_F3, true, false); //right wheel
	motor[1] = InitializeMotor(PIN_F0, PIN_F1, true, true); //left wheel
	adc[0] = InitializeADC(PIN_E5);


	SetMotor (motor[1], -.15);
	SetMotor (motor[0], -.150);
	
	while(1){

		ADCValue = ADCRead(adc[0]);
	//	ADCValue *= 1000; 
	SetMotor (motor[0], -.15 * ADCValue); //change the right wheel only
  
	Printf("IR1 values: %d\t", (int)(1000 * ADCValue));	
		Wait(.01);
		
		

		
			
	/*	if (ADCValue <= 600) {
			SetMotor(motor[0], -0.35);  
			SetMotor(motor[1], -0.25);
		}
		
		else  {
			SetMotor(motor[0], -.25); 
			SetMotor(motor[1], -0.35);
		}
*/			
		
		
		/*
		if (ADCValue >= 700){
			SetMotor(motor[0], -0.15); //turn right
			SetMotor(motor[1], -.25);
		}
		
		if (ADCValue <= 600 &&  ADCValue>400) {
			SetMotor(motor[0], -0.25); //turn Left 
			SetMotor(motor[1], -.20);
		}
		
		else if (ADCValue < 400) {
			SetMotor(motor[0], -0.30); //turn Left Faster
			SetMotor(motor[1], -0.00);
		}
		
		else { 
			SetMotor(motor[1], -0.25); 
			SetMotor(motor[0], -0.25);
		}
		*/
		/*		read = LineSensorRead(ls, 0.75);
	//	Printf("%x ", read);
	//	Wait(1);
		if (read >= 1 && read <= 40){
			SetMotor(motor[0], -0.40); //turn left - tested at -0.30
			SetMotor(motor[1], 0.00);
		}
		else if (read >= 150 && read < 255){ //tested at 90
			SetMotor(motor[1], -0.40); //turn right - tested at -0.30
			SetMotor(motor[0], 0.00);
		}
//slow down if no line	
		else if (read == 0) {
			SetMotor(motor[0], -0.15);
			SetMotor(motor[1], -0.15);
		} */
	/* 255 = all black line	
		else if (read == 255) {
			SetMotor(motor[0], 0.0);
			SetMotor(motor[1], 0.0);
		} 
	*/	
	/*	else{
			SetMotor(motor[0], -0.30);
			SetMotor(motor[1], -0.30);
		}
		*/
	}
}

