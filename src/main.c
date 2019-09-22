#include "botones.h"
#include "sapi.h"


int pin1= TEC1;
int pin2= TEC4;

void onPress(void) {
	gpioWrite(LEDR, ON);
	gpioWrite(LEDG, ON);
}

void onRelease(void) {
	gpioWrite(LEDR, OFF);
	gpioWrite(LEDG, OFF);
}
void onPress1(void) {
	gpioWrite(LED3, ON);
}

void onRelease1(void) {
	gpioWrite(LED3, OFF);
}

///mas uno q cuando apreto prenda y hasta q no lo vuelva a apretar no se apague!!!


int main(void) {
	boardConfig();
	Boton boton;
	Boton boton1;


	estadoIniciar(&boton, onPress, onRelease,pin1);
	estadoIniciar(&boton1, onPress1, onRelease1,pin2);


	while (1) {
		estado(&boton);
		estado(&boton1);
		delay(10);
	}

}
