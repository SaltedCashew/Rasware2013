#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/common.h>

// The 'main' function is the entry point of the program
void delay(int);
void SetPin(tPin, tBoolean);
int main(void) {
	InitializeMCU();
	
  while (1) {
		SetPin(PIN_F3, true);
		Wait(0.5);
		SetPin(PIN_F3, false);
		Wait(0.5);
	}
}
