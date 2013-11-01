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
//	tMotor *motor[2];
	float ADCValue;
	//float ADCValue2;
	//float ADCValue3;
	InitializeMCU();
	bus = InitializeI2C(PIN_B3, PIN_B2);
	ls = InitializeLineSensor(bus, 0);
//	motor[0] = InitializeMotor(PIN_C5, PIN_C4, true, false); //right wheel
//	motor[1] = InitializeMotor(PIN_B7, PIN_B6, true, false); //left wheel
	adc[0] = InitializeADC(PIN_E5);
//	adc[1] = InitializeADC(PIN_D1);
 // adc[2] = InitializeADC(PIN_D2);
//adc[3] = InitializeADC(PIN_D3);
	//SetMotor(motor[0], -0.30); //Good at -0.20
	//SetMotor(motor[1], -0.30); //Good at -0.20
	
	
	while(1){

		ADCValue = ADCRead(adc[0]);
//		ADCValue2 = ADCRead(adc[1]);
//		ADCValue3 = ADCRead(adc[2]);
		
		Printf("IR1 values: %d\t", (int)(1000 * ADCValue));
	//	Printf("/n IR2 values: %d\t", (int)(1000 * ADCValue1));
	//	Printf("/n IR3 values: %d\t", (int)(1000 * ADCValue2));
		
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

